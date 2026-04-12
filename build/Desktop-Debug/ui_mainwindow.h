/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <areadesenho.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSalvar;
    QAction *actionAbrir;
    QAction *actionRecentes;
    QAction *actionConfigura_es;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    AreaDesenho *areaDesenho;
    QMenuBar *menubar;
    QMenu *menuArquivo;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_3;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnEsquerda;
    QPushButton *btnCima;
    QPushButton *btnDireita;
    QPushButton *btnBaixo;
    QComboBox *comboForma;
    QPushButton *btnFechar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1272, 850);
        actionSalvar = new QAction(MainWindow);
        actionSalvar->setObjectName(QString::fromUtf8("actionSalvar"));
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName(QString::fromUtf8("actionAbrir"));
        actionRecentes = new QAction(MainWindow);
        actionRecentes->setObjectName(QString::fromUtf8("actionRecentes"));
        actionConfigura_es = new QAction(MainWindow);
        actionConfigura_es->setObjectName(QString::fromUtf8("actionConfigura_es"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        areaDesenho = new AreaDesenho(centralwidget);
        areaDesenho->setObjectName(QString::fromUtf8("areaDesenho"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(areaDesenho->sizePolicy().hasHeightForWidth());
        areaDesenho->setSizePolicy(sizePolicy);
        areaDesenho->setFrameShape(QFrame::StyledPanel);
        areaDesenho->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(areaDesenho);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1272, 20));
        menuArquivo = new QMenu(menubar);
        menuArquivo->setObjectName(QString::fromUtf8("menuArquivo"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy1);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        sizePolicy.setHeightForWidth(dockWidgetContents_3->sizePolicy().hasHeightForWidth());
        dockWidgetContents_3->setSizePolicy(sizePolicy);
        dockWidget->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidget_2->setMinimumSize(QSize(150, 35));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        layoutWidget = new QWidget(dockWidgetContents_4);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 82, 116));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnEsquerda = new QPushButton(layoutWidget);
        btnEsquerda->setObjectName(QString::fromUtf8("btnEsquerda"));

        verticalLayout_2->addWidget(btnEsquerda);

        btnCima = new QPushButton(layoutWidget);
        btnCima->setObjectName(QString::fromUtf8("btnCima"));

        verticalLayout_2->addWidget(btnCima);

        btnDireita = new QPushButton(layoutWidget);
        btnDireita->setObjectName(QString::fromUtf8("btnDireita"));

        verticalLayout_2->addWidget(btnDireita);

        btnBaixo = new QPushButton(layoutWidget);
        btnBaixo->setObjectName(QString::fromUtf8("btnBaixo"));

        verticalLayout_2->addWidget(btnBaixo);

        comboForma = new QComboBox(dockWidgetContents_4);
        comboForma->addItem(QString());
        comboForma->addItem(QString());
        comboForma->addItem(QString());
        comboForma->setObjectName(QString::fromUtf8("comboForma"));
        comboForma->setGeometry(QRect(20, 140, 79, 23));
        btnFechar = new QPushButton(dockWidgetContents_4);
        btnFechar->setObjectName(QString::fromUtf8("btnFechar"));
        btnFechar->setGeometry(QRect(10, 170, 101, 31));
        dockWidget_2->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, dockWidget_2);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuArquivo->menuAction());
        menuArquivo->addAction(actionSalvar);
        menuArquivo->addAction(actionAbrir);
        menuArquivo->addAction(actionRecentes);
        menuArquivo->addAction(actionConfigura_es);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSalvar->setText(QCoreApplication::translate("MainWindow", "Salvar", nullptr));
        actionAbrir->setText(QCoreApplication::translate("MainWindow", "Abrir", nullptr));
        actionRecentes->setText(QCoreApplication::translate("MainWindow", "Recentes", nullptr));
        actionConfigura_es->setText(QCoreApplication::translate("MainWindow", "Configura\303\247\303\265es", nullptr));
        menuArquivo->setTitle(QCoreApplication::translate("MainWindow", "Arquivo", nullptr));
        btnEsquerda->setText(QCoreApplication::translate("MainWindow", "\342\226\266", nullptr));
        btnCima->setText(QCoreApplication::translate("MainWindow", "\342\226\262", nullptr));
        btnDireita->setText(QCoreApplication::translate("MainWindow", "\342\227\200", nullptr));
        btnBaixo->setText(QCoreApplication::translate("MainWindow", "\342\226\274", nullptr));
        comboForma->setItemText(0, QCoreApplication::translate("MainWindow", "Ponto", nullptr));
        comboForma->setItemText(1, QCoreApplication::translate("MainWindow", "Reta", nullptr));
        comboForma->setItemText(2, QCoreApplication::translate("MainWindow", "Poligono", nullptr));

        btnFechar->setText(QCoreApplication::translate("MainWindow", "Fechar Pol\303\255gono", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
