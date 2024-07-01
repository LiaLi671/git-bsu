#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTextStream>
#include <QString>
#include <QFile>
#include "struct1.h"
#include "struct2.h"
#include "shablon.h"
Array<struct1> B;
Array<struct2> S;
int Ind;
QFile f1("C:/projects Qt/build-tab0-Desktop_Qt_6_6_1_MinGW_64_bit-Debug/debug/input1");
QFile f2("C:/projects Qt/build-tab0-Desktop_Qt_6_6_1_MinGW_64_bit-Debug/debug/input2");
QFile f10("C:/projects Qt/build-tab0-Desktop_Qt_6_6_1_MinGW_64_bit-Debug/debug/output1");
QFile f20("C:/projects Qt/build-tab0-Desktop_Qt_6_6_1_MinGW_64_bit-Debug/debug/output2");
QStandardItemModel *model1;
QStandardItemModel *model2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setWindowTitle("Table1");
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->tableView->hide();
    ui->label->hide();
    ui->label_2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_comboBox_activated(int index)
{
    if (index == 0){
        ui->lineEdit->hide();
        ui->lineEdit_2->hide();
        ui->lineEdit_3->hide();
        ui->lineEdit_4->hide();
        ui->lineEdit_5->hide();
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->pushButton_4->hide();
        ui->pushButton_5->hide();
        ui->tableView->hide();
        ui->label->hide();
        ui->label->hide();
        Ind = 0;
    }
    if (index == 1) {
        ui->lineEdit -> setVisible(true);
        ui->lineEdit_2 -> setVisible(true);
        ui->lineEdit_3 -> setVisible(true);
        ui->lineEdit_4->setVisible(true);
        ui->lineEdit_5->setVisible(true);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);
        ui->pushButton_5->setVisible(true);
        ui->tableView->setVisible(true);
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
        ui->label->setText("...");
        ui->label_2->setText("...");
        model1=new QStandardItemModel(4,3);
        model1->setHeaderData(0,Qt::Horizontal,"Book's name");
        model1->setHeaderData(1,Qt::Horizontal,"Amount");
        model1->setHeaderData(2,Qt::Horizontal,"Cost");

        if(f1.isOpen()){
            QTextStream in1(&f1);
            in1 >> B;
            for(size_t i = 0; i < B.data.size(); i++){
                model1->setItem(i,0,new QStandardItem(B.data[i].Name));
                model1->setItem(i,1,new QStandardItem(QString::number(B.data[i].Amount)));
                model1->setItem(i,2,new QStandardItem(QString::number(B.data[i].Cost)));
            }
            f1.close();
        }
        ui->tableView->setModel(model1);
        Ind = 1;
    }
    if (index == 2){
        ui->lineEdit -> setVisible(true);
        ui->lineEdit_2 -> setVisible(true);
        ui->lineEdit_3 -> hide();
        ui->lineEdit_4->setVisible(true);
        ui->lineEdit_5->setVisible(true);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);
        ui->pushButton_5->setVisible(true);
        ui->tableView->setVisible(true);
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
        ui->label->setText("...");
        ui->label_2->setText("...");
        model2=new QStandardItemModel(3,2);
        model2->setHeaderData(0,Qt::Horizontal,"ID");
        model2->setHeaderData(1,Qt::Horizontal,"Student's name");

        if (f2.isOpen()){
            QTextStream in2(&f2);
            in2 >> S;
            for(size_t i = 0; i < S.data.size(); i++){
                model2->setItem(i,0,new QStandardItem(QString::number(S.data[i].id)));
                model2->setItem(i,1,new QStandardItem(S.data[i].student_name));
            }
            f2.close();
        }
        ui->tableView->setModel(model2);
        Ind = 2;
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("...");
    ui->label_2->setText("...");
    if (Ind == 1){
        QString n=ui->lineEdit->text();
        int a = ui->lineEdit_2->text().toInt();
        double c = ui->lineEdit_3->text().toDouble();
        struct1 s1(a, c, n);
        ui->tableView->model()->insertRow(ui->tableView->model()->rowCount());
        model1->setItem(ui->tableView->model()->rowCount()-1,0,new QStandardItem(n));
        model1->setItem(ui->tableView->model()->rowCount()-1,1,new QStandardItem(QString::number(a)));
        model1->setItem(ui->tableView->model()->rowCount()-1,2,new QStandardItem(QString::number(c)));
        B.data.push_back(s1);
    }
    if (Ind == 2){
        int id = ui->lineEdit->text().toInt();
        QString s = ui->lineEdit_2->text();
        struct2 s2(id, s);
        ui->tableView->model()->insertRow(ui->tableView->model()->rowCount());
        model2->setItem(ui->tableView->model()->rowCount()-1,0,new QStandardItem(QString::number(id)));
        model2->setItem(ui->tableView->model()->rowCount()-1,1,new QStandardItem(s));
        S.data.push_back(s2);
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->label->setText("...");
    ui->label_2->setText("...");
    if(Ind == 1){
        int RowNum=ui->lineEdit_4->text().toInt();
        if(RowNum>ui->tableView->model()->rowCount()|| ui->tableView->model()->rowCount()<0){
            ui->lineEdit_4->setText("Enter less number");
            return;
        }
        model1->removeRow(RowNum-1);
        ui->lineEdit_4->clear();
        B.data.pop_back();
    }
    if(Ind == 2){
        int RowNum=ui->lineEdit_4->text().toInt();
        if(RowNum>ui->tableView->model()->rowCount() || ui->tableView->model()->rowCount()<0){
            ui->lineEdit_4->setText("Enter less number");
            return;
        }
        model2->removeRow(RowNum-1);
        ui->lineEdit_4->clear();
        S.data.pop_back();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->label->setText("...");
    ui->label_2->setText("...");
    if(Ind == 1){
        sort(B.data.begin(),B.data.end(),[](const struct1& obj,const struct1& obj2){
            return obj.Name<obj2.Name;
        });
        for(size_t i = 0; i < B.data.size(); i++){
            model1->setItem(i,0,new QStandardItem(B.data[i].Name));
            model1->setItem(i,1,new QStandardItem(QString::number(B.data[i].Amount)));
            model1->setItem(i,2,new QStandardItem(QString::number(B.data[i].Cost)));
        }
        ui->tableView->setModel(model1);

    }
    if(Ind == 2){
        sort(S.data.begin(),S.data.end(),[](const struct2& obj,const struct2& obj2){
            return obj.student_name<obj2.student_name;
        });
        for(size_t i = 0; i < S.data.size(); i++){
            model2->setItem(i,0,new QStandardItem(QString::number(S.data[i].id)));
            model2->setItem(i,1,new QStandardItem(S.data[i].student_name));
        }
        ui->tableView->setModel(model2);

    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QString text=ui->lineEdit_5->text();
    QString res;
    if(Ind == 1){
        for(int i = 0; i < ui->tableView->model()->rowCount();i++){
            QModelIndex ind=model1->index(i,0);
            QVariant data=ind.data();
            QString Name=data.toString();
            if(Name == text){
                res+=Name;
                res+=" ";
                ind=model1->index(i,1);
                data=ind.data();
                Name=data.toString();
                res+=Name;
                ui->label_2->setText(res);
                return;
            }
        }
        ui->label_2->setText("Not found");
    }
    if(Ind == 2){
        QString text=ui->lineEdit_5->text();
        QString res;
        for(int i = 0; i < ui->tableView->model()->rowCount(); i++){
            QModelIndex ind=model2->index(i,0);
            QVariant data=ind.data();
            QString Name=data.toString();
            if(Name==text){
                res+=Name;
                res+=" ";
                ind=model2->index(i,1);
                data=ind.data();
                Name=data.toString();
                res+=Name;
                ind=model2->index(i,2);
                data=ind.data();
                Name=data.toString();
                res+=" ";
                res+=Name;
                ui->label_2->setText(res);
                return;
            }
        }
        ui->label_2->setText("Not found");
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->label_2->setText("...");
    if(Ind == 1){
        if(f10.open(QIODevice::WriteOnly)){
            QTextStream out(&f10);
            out << B;
            ui->label->setText("Saved");
            f10.close();
        }
    }
    if(Ind == 2){
        if(f20.open(QIODevice::WriteOnly)){
            QTextStream out(&f20);
            out << S;
            ui->label->setText("Saved");
            f20.close();
        }
    }
}

