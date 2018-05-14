#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_spinBoxA_valueChanged(int arg1);

    void on_spinBoxB_valueChanged(int arg1);

    void on_pushButtonGo_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
