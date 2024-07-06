#include "paintscene.h"
#include "romb.h"
#include "square.h"
#include "oval.h"

paintScene::paintScene(QObject *parent, QColor& color_p): c(color_p) {}
paintScene::paintScene(QObject *parent) : QGraphicsScene(parent), c(Qt::red), vect1(0) {}

paintScene::~paintScene() {}

int paintScene::typeFigure() const
{
    return m_typeFigure;
}

void paintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем конечную координату положения мыши
     * в текущую отрисовываемую фигуру
     * */
    tempFigure->setEndPoint(event->scenePos());
    /* Обновляем содержимое сцены,
     * необходимо для устранения артефактов при отрисовке фигур
     * */
    this->update(QRectF(0,0,this->width(), this->height()));
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_typeFigure) {
   case SquareType: {
        Square *item = new Square(event->scenePos(),c);
        item->setPos(event->pos());
        tempFigure = item;
        vect1.Push(item,0);
        break;
    }
    case RombType: {
        Romb *item = new Romb(event->scenePos(),c);
        item->setPos(event->pos());
        tempFigure = item;
        vect1.Push(item,2);
        break;
    }
    case OvalType:{
        Figure *item = new Oval(event->scenePos(),c);
        item->setPos(event->pos());
        tempFigure = item;
        vect1.Push(item,1);
        break;
    }
    default:{
        Square *item = new Square(event->scenePos(), c);
        item->setPos(event->pos());
        tempFigure = item;
        vect1.Push(item,0);
        break;
    }
    }
    this->addItem(tempFigure);
}
