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

    Set ArrA;
    Set ArrB;

    Set Plus;

    QString table;
    QString My;
    for(int i =0;i< ui->tableWidgetA->columnCount();i++ )
    {
    ArrA.Add(ui->tableWidgetA->item(0,i)->text().toInt());
    table +="  " ;
    table += ui->tableWidgetA->item(0,i)->text();
    }


    for(int i =0;i< ArrA .getSizePlural();i++ )
    {
        My +="  " ;
        My += QString::number(ArrA.At(i));
    }



    qDebug()<<"My Table 0 " << table;
    qDebug()<<"My 0 " << My;
    table ="";
    My="";
    for(int i =0;i< ui->tableWidgetB->columnCount();i++ )
    {
        ArrB.Add(ui->tableWidgetB->item(0,i)->text().toInt());
        table +="  " ;
        table+=ui->tableWidgetB->item(0,i)->text();
    }

    for(int i =0;i< ArrB .getSizePlural();i++ )
    {
        My +="  " ;
        My += QString::number(ArrB.At(i));
    }


    qDebug()<<"My Table 1 " << table;
    qDebug()<<"My 1" << My;

    table ="";
    My="";

    if(ArrA.inlude(ui->spinBoxElement->value()))
    {
        ui->labelElement->setText("Yes");
    }
    else
    {
        ui->labelElement->setText("No");
    }

    Plus = ArrA + ArrB;

    qDebug()<<"finish :";
    for(int i = 0 ;i<Plus.getSizePlural();i++)
    {
        qDebug()<<Plus.At(i);
    }

    ui->tableWidgetAdding->setColumnCount(Plus.getSizePlural());
  qDebug()<<"finish :1";

        ui->tableWidgetAdding->clear();
        ui->tableWidgetAdding->setRowCount(1);
        ui->tableWidgetAdding->setColumnCount(Plus.getSizePlural());
        for (auto r=0; r<1; r++)
             for (auto c=0; c<Plus.getSizePlural(); c++)
                  ui->tableWidgetAdding->setItem( r, c, new QTableWidgetItem(QString::number(Plus.At(c))));




}
