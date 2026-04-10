#ifndef MAINWINDOW_H  //se nao tiver definido
#define MAINWINDOW_H //entao defina

#include <QMainWindow>

QT_BEGIN_NAMESPACE  //ponte em interface e back
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE //fim da ponte

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
