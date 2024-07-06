#include "paint.h"
#include "ui_paint.h"
#include <QColorDialog>
#include <QTextStream>
#include "mas.h"
#include "paintscene.h"
#include <QFile>
QFile file("C:/projects Qt/build-paint-Desktop_Qt_6_6_1_MinGW_64_bit-Debug/debug/output.txt");

Paint::Paint(QWidget *parent) : QMainWindow(parent), color(Qt::yellow), ui(new Ui::Paint) {
    ui->setupUi(this);
    scene = new paintScene(parent, color);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);                // Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Paint::slotTimer);
    timer->start(100);

}

Paint::~Paint()
{
    delete ui;
}

void Paint::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void Paint::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}

void Paint::on_action_5_triggered()
{
    scene->setTypeFigure(paintScene::SquareType);
}

void Paint::on_action_6_triggered()
{
    scene->setTypeFigure(paintScene::OvalType);
}

void Paint::on_action_7_triggered()
{
    scene->setTypeFigure(paintScene::RombType);
}

void Paint::on_action_9_triggered()
{
    color = QColorDialog::getColor(Qt::yellow, this);
    scene->c = color;
}

//удаление всего
void Paint::on_action_2_triggered()
{
    ui ->graphicsView ->scene()->clear();
    scene->vect1.data.clear();
}

//отмена шага
void Paint::on_action_3_triggered()
{
    scene->vect1.data.pop_back();
    ui ->graphicsView ->scene()->clear();
    for (size_t i = 0; i < scene->vect1.data.size(); i++){

    }
}

//Сохранить
void Paint::on_action_triggered()
{

    if (file.open(QIODevice::WriteOnly)){
        QTextStream out(&file);
        out << scene->vect1.size << "\n";
        out << scene->vect1;
    }
}

