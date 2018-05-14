#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"set.h"
#include<QDebug>
#include<string>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBoxA_valueChanged(int arg1)
{
    ui->tableWidgetA->setColumnCount(arg1);

}

void MainWindow::on_spinBoxB_valueChanged(int arg1)
{
    ui->tableWidgetB->setColumnCount(arg1);

}

void MainWindow::on_pushButtonGo_clicked()
{

    Set ArrA(ui->spinBoxA->value()),
    Set ArrB(ui->spinBoxB->value());

    for(int i =0;i< ui->tableWidgetA->columnCount();i++ )
    {
//        ArrA.Read( i ,ui->tableWidgetA->item(0,i)->text().toInt() );
    }

    for(int i =0;i< ui->tableWidgetB->columnCount();i++ )
    {
   //     ArrB.Read(i , ui->tableWidgetB->item(0,i)->text().toInt());
    }


    ui->tableWidgetA->resizeColumnsToContents();
    ui->tableWidgetB->resizeColumnsToContents();


}
