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
            Temp(ui->spinBoxA->value()-1);
    Set ArrB(ui->spinBoxB->value());

    for(int i =0;i< ui->tableWidgetA->columnCount();i++ )
    {
        ArrA.Read( i ,ui->tableWidgetA->item(0,i)->text().toInt() );
    }

    for(int i =0;i< ui->tableWidgetB->columnCount();i++ )
    {
        ArrB.Read(i , ui->tableWidgetB->item(0,i)->text().toInt());
    }

    bool Check = ArrA.InludeElement(ui->spinBoxElement->value());

    if( Check == true)
    {
        ui->labelElement->setText("Yes");
    }
    else
    {
        ui->labelElement->setText("No");
    }

    QString powerA = QString::number(ArrA.Power());
    ui->labelPowerA->setText(powerA);

    QString MaxElementA= QString::number (ArrA.MaxElement());
    ui->labelMaxElementA->setText(MaxElementA);

    QString MinElementA= QString::number (ArrA.MinElement());
    ui->labelMinElementA->setText(MinElementA);


    Set C(1),Adding(1);

    Adding = ArrA+ArrB;


    ui->tableWidgetAdding->setColumnCount(Adding.getSizePlural());

    for (int i = 0 ; i<Adding.getSizePlural();i++)
    {
        qDebug()<<Adding.OutPut(i);
    }


    ui->tableWidgetAdding->item(0,0)->setText(QString::number(Adding.OutPut(0)));

//    for (int i = 0 ; i<Adding.getSizePlural();i++)
//    {
//        qDebug()<<Adding.OutPut(i);


//    }
    //C=ArrA-ArrB;

    // C=ArrA/ArrB;

    //    C=ArrA;
    //    if(ui->spinBoxA->value()>1)
    //    {
    //        if(ui->spinBoxDeleteElment->value()>0)
    //        {

    //            C=C.DeleteElement(ui->spinBoxDeleteElment->value()-1);

    //            qDebug()<<"Size after"<<C.getSizePlural();

    //            ui->tableWidgetA->setColumnCount(C.getSizePlural());

    //            for(int i=0;i < C.getSizePlural();i++)
    //            {

    //                ui->tableWidgetA->item(0,i)->setText(QString ::number(C.OutPut(i)));
    //            }
    //            ui->spinBoxA->setValue(ui->spinBoxA->value()-1);
    //        }

    ui->tableWidgetA->resizeColumnsToContents();
    ui->tableWidgetB->resizeColumnsToContents();


}
