#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"
#include <QString>
#include <QTextStream>

#include <QPainter>
#include <QColor>

class Square: public Figure
{
    Q_OBJECT
public:
    explicit Square(QPointF point, QObject *parent = 0);
    ~Square();
    Square(QPointF point,  QColor & c2, int m_typeFigure = 0, QObject *parent = 0);
    QColor m_fillColor2;
    double x_vl, y_vl, x_vp, y_vp, x_np, y_np, x_nl, y_nl;
    int m_typeFigure2=0;
    int gettype(){
        return m_typeFigure2;
    }
    // friend QTextStream& operator<<(QTextStream& out, Square& r){
    //     out << r.m_typeFigure2 << "\t" << r.m_fillColor2.name() << "\n";
    //     out << r.x_vl << "\t" << r.y_vl  << "\t" <<  r.x_vp  << "\t" <<  r.y_vp  << "\t" << r.x_np  << "\t" << r.y_np  << "\t" <<  r.x_nl  << "\t" <<  r.y_nl << "\n";
    //     return out;
    // }

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SQUARE_H

