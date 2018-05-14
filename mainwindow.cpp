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

    Set ArrA(ui->spinBoxA->value());
    Set ArrB(ui->spinBoxB->value());
    Set Plus;

    for(int i =0;i< ui->tableWidgetA->columnCount();i++ )
    {
    ArrA.Add(ui->tableWidgetA->item(0,i)->text().toInt());
    }

    for(int i =0;i< ui->tableWidgetB->columnCount();i++ )
    {
        ArrB.Add(ui->tableWidgetB->item(0,i)->text().toInt());
    }

    if(ArrA.inlude(ui->spinBoxElement->value()))
    {
        ui->labelElement->setText("Yes");
    }
    else
    {
        ui->labelElement->setText("No");
    }
    Plus=ArrA+ArrB;

    for(int i = 0 ;i<Plus.getSizePlural();i++)
    {
      //  qDebug()<<Plus.At(i);
    }


    //    for(int i = 0 ; i <Plus.getSizePlural();)
//    {
//        ui->tableWidgetAdding->item(0,i)->setText(QString::number( Plus.At(i)));
//    }



    ui->tableWidgetA->resizeColumnsToContents();
    ui->tableWidgetB->resizeColumnsToContents();


}
