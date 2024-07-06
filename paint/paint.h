#ifndef PAINT_H
#define PAINT_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>
#include <figure.h>
#include <paintscene.h>
#include <mas.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Paint;
}
QT_END_NAMESPACE

class Paint : public QMainWindow
{
    Q_OBJECT 

public:
    Paint(QWidget *parent = nullptr);
    ~Paint();
    paintScene *scene;
    QColor color;
private:
    Ui::Paint *ui;
    QTimer *timer;
private:
    void resizeEvent(QResizeEvent * event);
    void slotTimer();

private slots:
    void on_action_5_triggered();
    void on_action_6_triggered();
    void on_action_7_triggered();
    void on_action_9_triggered();
    void on_action_2_triggered();
    void on_action_3_triggered();
    void on_action_triggered();
};
#endif // PAINT_H








