#ifndef ROMB_H
#define ROMB_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"
#include <QString>
#include <QTextStream>

#include <QPainter>
#include <QColor>

/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class Romb : public Figure
{
    Q_OBJECT

public:
    explicit Romb(QPointF point, QObject *parent = 0);
    ~Romb();
    Romb(QPointF point,  QColor & c1,int m_typeFigure = 1, QObject *parent = 0);
    QColor m_fillColor1;
    int m_typeFigure1=1;
    double x_vl, y_vl, x_vp, y_vp, x_np, y_np, x_nl, y_nl;

    int gettype(){
        return m_typeFigure1;
    }

    friend QTextStream& operator<<(QTextStream& out, Romb& r){
        out<<r.x_nl<<"\t"<<r.x_np<<" "<<r.x_vl<<" "<<r.x_vp<<" "<<r.y_nl<<" "<<r.y_np<<" "<<r.y_vl<<" "<<r.y_vp<<" ";

       out << r.m_typeFigure1 << "\t" << r.m_fillColor1.name() << "\n";


        return out;
    }

private:
    // Для Ромба реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ROMB_H
