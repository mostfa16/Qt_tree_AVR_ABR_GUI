#ifndef DIALOG_H
#define DIALOG_H
#include "abr.h"
#include <QDialog>
//#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include "avl.h"

#include "bicolor.h"
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsItemAnimation>
#include <queue>

using namespace std;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog, public abr
{
    Q_OBJECT

public:
    typedef queue<abr> qi;
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setinfo();
    void affichItem(abr *a);
    void affichfile(qi *f);


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void affichage(abr *a, int x, int y, int k, int xp);
    void affichage2(avl *a, int x, int y, int k, int xp);
    void affichage3(bicolor *a, int x, int y, int k, int xp);

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene,*scene2,*scene3;
    //QGraphicsScene *scene3;
    abr *ab;
    avl *av;
    bicolor *bi;
    int tai,tai2;

    QGraphicsEllipseItem *ellipse,*ellipse2,*ellipse3 ;
    QGraphicsTextItem *text,*text2,*text3 ;
    QGraphicsLineItem *line,*line2,*line3;


};

#endif // DIALOG_H
