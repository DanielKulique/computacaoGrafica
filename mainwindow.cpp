#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Poligono.h"
#include <QColorDialog>
#include <QSpinBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->areaDesenho->setModo("ponto");

    float passo = 10.0f;

    connect(ui->btnCima,     &QPushButton::clicked, this, [=](){
        ui->areaDesenho->moverObjetos(0, -passo);
    });
    connect(ui->btnBaixo,    &QPushButton::clicked, this, [=](){
        ui->areaDesenho->moverObjetos(0, +passo);
    });
    connect(ui->btnEsquerda, &QPushButton::clicked, this, [=](){
        ui->areaDesenho->moverObjetos(+passo, 0);
    });
    connect(ui->btnDireita,  &QPushButton::clicked, this, [=](){
        ui->areaDesenho->moverObjetos(-passo, 0);
    });
    connect(ui->comboForma, &QComboBox::currentTextChanged, this, [=](const QString &texto) {
        ui->areaDesenho->setModo(texto.toLower());
    });
    connect(ui->btnFechar, &QPushButton::clicked, this, [=]() {
        if (ui->areaDesenho->pontosTemporarios.size() >= 3) {

            QString nome = QString("Polígono %1").arg(ui->areaDesenho->contadorPoligono++);

            Poligono* novoPoligono = new Poligono(nome, ui->areaDesenho->pontosTemporarios);

            novoPoligono->minhaCor = ui->areaDesenho->corAtual;
            novoPoligono->minhaEspessura = ui->areaDesenho->espessuraAtual;

            ui->areaDesenho->displayFile.adicionar(novoPoligono);

            ui->listWidget->addItem(nome);
            ui->areaDesenho->pontosTemporarios.clear();
            ui->areaDesenho->update();
        }
    });
    connect(ui->areaDesenho, &AreaDesenho::novoObjetoCriado, this, [=](QString nomeObjeto) {
        ui->listWidget->addItem(nomeObjeto);
    });
    connect(ui->btnCor, &QPushButton::clicked, this, [=]() {
        QColor cor = QColorDialog::getColor(ui->areaDesenho->corAtual, this, "Escolha a Cor");
        if (cor.isValid()) {
            ui->areaDesenho->corAtual = cor;
            ui->areaDesenho->update();
        }
    });
    connect(ui->spinEspessura, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int novaEspessura) {
        ui->areaDesenho->espessuraAtual = novaEspessura;
        ui->areaDesenho->update();
    });

    connect(ui->SalvarPNG, &QAction::triggered, this, [=]() {

        QString nomeFicheiro = QFileDialog::getSaveFileName(this, "Guardar Display File", "", "Ficheiros de Texto (*.txt)");

        if (nomeFicheiro.isEmpty()) return;

        QFile ficheiro(nomeFicheiro);
        if (!ficheiro.open(QIODevice::WriteOnly | QIODevice::Text)) return;

        QTextStream saida(&ficheiro);

        for (Objeto* obj : ui->areaDesenho->displayFile.objetos) {

            saida << obj->tipo << ";" << obj->nome << ";"
                  << obj->minhaCor.name() << ";" << obj->minhaEspessura;

            for (const Ponto& p : obj->pontos) {
                saida << ";" << p.getX() << "," << p.getY();
            }

            saida << "\n";
        }

        ficheiro.close();
    });
    connect(ui->actionSalvar, &QAction::triggered, this, [=]() {

        QString nomeArquivo = QFileDialog::getSaveFileName(this, "Salvar Desenho", "", "Imagens PNG (*.png)");

        if (nomeArquivo.isEmpty()) return;

        // A CORREÇÃO MÁGICA: Se o usuário esquecer de digitar .png no final, o código coloca por ele!
        if (!nomeArquivo.endsWith(".png", Qt::CaseInsensitive)) {
            nomeArquivo += ".png";
        }

        QPixmap imagem = ui->areaDesenho->grab();

        // Tenta salvar e guarda o resultado (true ou false)
        bool sucesso = imagem.save(nomeArquivo, "PNG", 100);

        // Avisa no terminal do Qt Creator se deu certo ou errado
        if (sucesso) {
            qDebug() << "Imagem salva com sucesso em:" << nomeArquivo;
        } else {
            qDebug() << "ERRO: O Qt não conseguiu salvar a imagem.";
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
