#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Poligono.h"
#include "ObjetoPonto.h"
#include "Reta.h"

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
            ui->areaDesenho->displayFile.adicionar(
                new Poligono("poligono", ui->areaDesenho->pontosTemporarios)
                );
            ui->areaDesenho->pontosTemporarios.clear();
            ui->areaDesenho->update();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
