#ifndef OVAL_H
#define OVAL_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"
#include <QTextStream>
#include <QString>

#include <QPainter>
#include <QColor>

class Oval: public Figure
{
    Q_OBJECT
public:
    explicit Oval(QPointF point, QObject *parent = 0);
    Oval(QPointF point,  QColor & c, int m_typeFigure2 = 2, QObject *parent = 0);
    ~Oval();
    QColor m_fillColor;
    int m_typeFigure2=2;
    double centerx,centery,rx1,ry1;
    int gettype(){
        return m_typeFigure2;
    }
    friend QTextStream& operator<<(QTextStream& out, Oval& r){
        out << r.m_typeFigure2 << "\t" << r.m_fillColor.name() << "\n";
        out<<r.centerx<<"\t"<<r.centery<<"\t"<<r.rx1<<"\t"<<r.ry1<<"\n";
        return out;
    }
private:
    // Для Ромба реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // OVAL_H
