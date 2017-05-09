#include "dialog.h"
#include "ui_dialog.h"
#include <qgraphicsview>
//#include <QtCore>
//#include <QtGui>
#include <queue>
#include <QTime>
#include <qmessagebox.h>
#include <QGraphicsItemAnimation>
#include <QRegExp>

using namespace std;
typedef queue<abr> qi;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene =new QGraphicsScene(this);
    scene2 =new QGraphicsScene(this);
    scene3 =new QGraphicsScene(this);


    ui->graphicsView->setScene(scene);
    ui->graphicsView_2->setScene(scene2);
    ui->graphicsView_3->setScene(scene3);

    ab=NULL;    ab->ajout(ab,67);    ab->ajout(ab,49);    ab->ajout(ab,88);    ab->ajout(ab,50);    ab->ajout(ab,186);
    av=NULL;    av->ajout(av,35);    av->ajout(av,62);    av->ajout(av,97);    av->ajout(av,77);    av->ajout(av,81);
    bi=NULL;
    bicolor *z,*q;
   // q=new bicolor;z=new bicolor;
    //q->val=1;z->val=1;
    //qDebug()<<"dd";

   // q->d=NULL;q->g=NULL;q->coul=rouge;
   // qDebug()<<"aa";

   // z->d=q;z->g=q;z->coul=blanc;
    //qDebug()<<"azaz";

    bool zz;zz=true;
    //bi->g=z;bi->d=NULL;
    bicolor *b2,*b3,*b4,*b5;
    b2=new bicolor;b2->val=11;b2->g=NULL;b2->d=NULL;b2->coul=rouge;
    b3=new bicolor;b3->val=88;b3->g=NULL;b3->d=NULL;b3->coul=rouge;
    bi=new bicolor;bi->val=23;bi->g=b2;bi->d=b3;bi->coul=blanc;
    //bi->rech_adj_bic(44,  z, q,bi,zz);
  //  bi->rech_adj_bic(22,z,z,z,true);
//qDebug()<<"a="<<bi->coul<<"b="<<bi->g->coul<<"c="<<bi->d->coul;
tai=ab->nbrfeille(ab);
tai2=av->nbrfeille(av);

affichage(ab,0,0,tai*25,0);
affichage2(av,0,0,tai2*25,0);qDebug()<<"sss";

affichage3(bi,0,0,tai*25,0);
//qDebug()<<"dd";

    setinfo();
  //  qDebug()<<"qq";

}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::affichage(abr *a, int x, int y, int k, int xp)
{QBrush brush(Qt::yellow);

 //ellipse->setBrush(Qt::white);
    if (a==NULL) return;
 QString s = QString::number(a->val);
 //ui->textBrowser->append(s);

 ellipse=scene->addEllipse(x,y,50,50);ellipse->setBrush(brush);
 if(x!=0)
{
// ellipse->setFlag(QGraphicsEllipseItem::ItemIsMovable);
 text = scene->addText(s, QFont("Arial", 18) );
// text->setFlag(QGraphicsEllipseItem::ItemIsMovable);
 text->moveBy(x+10,y+10);
 line =scene->addLine(xp+25,y,x+25,y);

  if((a->g)!=NULL) {   affichage(a->g,x-k,y+50,k*0.7,x);}
  if((a->d)!=NULL) {  affichage(a->d,x+k,y+50,k*0.7,x);}
}else {

 //ellipse->setFlag(QGraphicsEllipseItem::ItemIsMovable);
 text = scene->addText(s, QFont("Arial", 18) );
 //text->setFlag(QGraphicsEllipseItem::ItemIsMovable);
 text->moveBy(x+10,y+10);

  if((a->g)!=NULL) {   affichage(a->g,x-k,y+50,k*0.7,x);}
  if((a->d)!=NULL) {  affichage(a->d,x+k,y+50,k*0.7,x);}
}
}

void Dialog::affichage2(avl *a, int x, int y, int k, int xp)
{QBrush brush(Qt::green);

 //ellipse->setBrush(Qt::white);
    if (a==NULL) return;
 QString sss = QString::number(a->val);
 QString ss = QString::number(a->des);
 QString s=sss+"("+ss+")";
 //ui->textBrowser->append(s);

 ellipse2=scene2->addEllipse(x,y,50,50);ellipse2->setBrush(brush);
 if(x!=0)
{
// ellipse->setFlag(QGraphicsEllipseItem::ItemIsMovable);
 text2 = scene2->addText(s, QFont("Arial", 11) );
// text->setFlag(QGraphicsEllipseItem::ItemIsMovable);
 text2->moveBy(x+5,y+5);
 line2 =scene2->addLine(xp+25,y,x+25,y);

  if((a->g)!=NULL) {   affichage2(a->g,x-k,y+50,k*0.7,x);}
  if((a->d)!=NULL) {  affichage2(a->d,x+k,y+50,k*0.7,x);}
}else {

 //ellipse->setFlag(QGraphicsEllipseItem::ItemIsMovable);
 text2 = scene2->addText(s, QFont("Arial", 11) );
 //text->setFlag(QGraphicsEllipseItem::ItemIsMovable);
 text2->moveBy(x+10,y+10);

  if((a->g)!=NULL) {   affichage2(a->g,x-k,y+50,k*0.7,x);}
  if((a->d)!=NULL) {  affichage2(a->d,x+k,y+50,k*0.7,x);}
}
}
void Dialog::affichage3(bicolor *a, int x, int y, int k, int xp)
{QBrush brush(Qt::white);

 //ellipse->setBrush(Qt::white);
    if (a==NULL) return;
  QString h,s,d,f,hh;
          h = QString::number(a->val);d="";f="";
          hh=QString::number(a->coul);
          hh=(hh=="0")?"r":"b";
          h = h+"("+hh+")";
 if(a->d!=NULL){if(a->d->coul=rouge)d=QString::number(a->d->val);}
 if(a->g!=NULL){if(a->g->coul=rouge)f=QString::number(a->g->val);}
 //qDebug()<<"h : "<<h;
 //qDebug()<<"d : "<<d;
 //qDebug()<<"f : "<<f;
 s=d+h+f;
 //qDebug()<<"ks : "<<s;
     //ui->textBrowser->append(s);

 ellipse3=scene3->addEllipse(x,y,50,50);ellipse3->setBrush(brush);
 if(x!=0)
{
// ellipse->setFlag(QGraphicsEllipseItem::ItemIsMovable);
 text3 = scene3->addText(s, QFont("Arial", 11) );
// text->setFlag(QGraphicsEllipseItem::ItemIsMovable);
 text3->moveBy(x+10,y+10);
 line3 =scene3->addLine(xp+25,y,x+25,y);

  if((a->g)!=NULL) {   affichage3(a->g,x-k,y+50,k*0.7,x);ellipse3->setBrush(Qt::white);}
  if((a->d)!=NULL) {  affichage3(a->d,x+k,y+50,k*0.7,x);ellipse3->setBrush(Qt::white);}
}else {

 //ellipse->setFlag(QGraphicsEllipseItem::ItemIsMovable);
 text3 = scene3->addText(s, QFont("Arial", 11) );
 //text->setFlag(QGraphicsEllipseItem::ItemIsMovable);
 text3->moveBy(x+10,y+10);

  if((a->g)!=NULL) {   affichage3(a->g,x-k,y+50,k*0.7,x);ellipse3->setBrush(Qt::red);}
  if((a->d)!=NULL) {  affichage3(a->d,x+k,y+50,k*0.7,x);ellipse3->setBrush(Qt::red);}
}
}


void Dialog::on_pushButton_3_clicked()
{
    QString a=ui->lineEdit_3->text();
    int aa=a.toInt();
    bool tr;
    tr=ab->recherche(ab,aa);
    affichage_infixe(ab);
    //affichItem(ab);
    qDebug()<<tr;
    if(tr){
        QString sss=QString("L'elt %1 existe dans cet abr").arg(aa);
        QMessageBox::information(this, "Trouvé!", sss);
                    return;
           }
    else{
        QString sss=QString("L'elt %1 n'existe pas dans cet abr").arg(aa);
        QMessageBox::information(this, "Non Trouvé!", sss);
                    return;

}//affichage(ab,0,0,50,0);
}

void Dialog::on_pushButton_2_clicked()
{
    QString a=ui->lineEdit_2->text();
    int aa=a.toInt();
    qDebug()<<"elt a supp : "<<aa;
    QTime t;
    t.start();
    ab->supprimer(ab,aa);
    setinfo();tai=ab->nbrfeille(ab);;

    qDebug("Time elapsed: %d ms", t.elapsed());
    scene->clear();
affichage(ab,0,0,tai*25,0);
}

void Dialog::on_pushButton_clicked()
{
    QString a=ui->lineEdit->text();
    int aa=a.toInt();
   // qDebug()<<aa;
    QTime t;
        t.start();
    ab->ajout(ab,aa);
    setinfo();tai=ab->nbrfeille(ab);
    qDebug()<<"elt a ajouter : "<<aa;
     qDebug("Time elapsed: %d ms", t.elapsed());
    scene->clear();
affichage(ab,0,0,tai*25,0);

}
void Dialog::setinfo()
{
//ui->lineEdit_7->setDisabled(true);
int i=ab->taille(ab);    int i2=ab->hauteur(ab);int i3=ab->nbrfeille(ab);
QString s1=QString("Taille = %1   Hauteur = %2   Nbr Feuille = %3").arg(i).arg(i2).arg(i3);
ui->lineEdit_7->setText(s1);

i=av->taille(av);    i2=av->hauteurA(av); i3=av->nbrfeille(av);
//QString s2=QString("Taille = %1 ").arg(i);
QString s2=QString("Taille = %1   Hauteur = %2   Nbr Feuille = %3").arg(i).arg(i2).arg(i3);

ui->lineEdit_8->setText(s2);

i=bi->taille(bi);   //  i2=bi->hauteur(bi); i3=bi->nbrfeille(bi);
//QString s3=QString("Taille = %1     Hauteur = %2     Nbr Feuille = %3").arg(i).arg(i2).arg(i3);
QString s3=QString("Taille = %1").arg(i);
ui->lineEdit_12->setText(s3);

}
///*
  void Dialog::affichItem(abr *a)
{int i=0;//QPainter *painter;
     // QRectF rec = boundingRect();
      //QBrush brush(Qt::white);
      //painter->setBrush(brush);
    if(a==NULL)return;
    qi q;
    q.push(*a);
     while(!q.empty())
    {i++; qDebug() <<"i"<<i;
         a=&q.front();
         qDebug() << a->GetVal()<<"getval" ;
        //square=new MySquare();
        //scene->addItem(square);
                 q.pop();
       if(a->g!=NULL) {q.push(a->GetG());qDebug() <<"push g";}         //emfiler(&te,&qu,a->g);
       if(a->d!=NULL) {q.push(a->GetD());qDebug() <<"push d";}         //emfiler(&te,&qu,a->d);

    }
}
  //*/
void Dialog::affichfile(qi *f)
{
    qDebug()<<"affichfile";
    while(!f->empty()){
        abr *dd;
        dd=&f->front();
        qDebug() << dd->GetVal() ;
                f->pop();
    }

}

void Dialog::on_pushButton_6_clicked()
{
    QString a=ui->lineEdit_6->text();
    int aa=a.toInt();
    bool tr;
    tr=av->recherche(av,aa);
    av->affichage_infixe(av);
    //affichItem(ab);
    qDebug()<<tr;
    if(tr){
        QString sss=QString("L'elt %1 existe dans cet avl").arg(aa);
        QMessageBox::information(this, "Trouvé!", sss);
                    return;
           }
    else{
        QString sss=QString("L'elt %1 n'existe pas dans cet avl").arg(aa);
        QMessageBox::information(this, "Non Trouvé!", sss);
                    return;

}}

void Dialog::on_pushButton_9_clicked()
{
    QString a=ui->lineEdit_11->text();
    int aa=a.toInt();
    bool tr;
    tr=bi->recherche(bi,aa);
    bi->affichage_infixe(bi);
    //affichItem(ab);
    qDebug()<<tr;
    if(tr){
        QString sss=QString("L'elt %1 existe dans cet arbre 2.3.4").arg(aa);
        QMessageBox::information(this, "Trouvé!", sss);
                    return;
           }
    else{
        QString sss=QString("L'elt %1 n'existe pas dans cet arbre 2.3.4").arg(aa);
        QMessageBox::information(this, "Non Trouvé!", sss);
                    return;

}}

void Dialog::on_pushButton_10_clicked()
{
    showMaximized();
}

void Dialog::on_pushButton_4_clicked()
{
    QString a=ui->lineEdit_4->text();
    int aa=a.toInt();
   // qDebug()<<aa;
    QTime t;
        t.start();
    av->ajout(av,aa);
    qDebug()<<"elt a ajouter : "<<aa;


       // av->ajoutAVL(av, NULL, true, aa);
//    av->ajouter(aa);
        setinfo();
    scene2->clear();
    tai2=av->nbrfeille(av);
    affichage2(av,0,0,tai2*25,0);
QString s1=QString("Aj: %1 ms").arg(t.elapsed());
//     QString s1=" ms"<< t.elapsed();
     ui->lineEdit_13->setText(s1);
  //  scene->clear();
//affichage(ab,0,0,80,0);
}

void Dialog::on_pushButton_7_clicked()
{QString a=ui->lineEdit_9->text();
    int aa=a.toInt();
    qDebug()<<"aa = "<<aa;
    QTime tt;
        tt.start();
        bicolor *z,*q;bool zz;
        //z=NULL;q=NULL;
        zz=true;
    //av->ajout(av,aa);
        bi->rech_adj_bic(aa,  z, q,bi,zz);
       // bi->rech_adj_bic(44,  bi->d, bi->g,bi,zz);
    setinfo();
   // qDebug()<<"elt a ajouter : "<<aa;
    // qDebug("Time elapsed: %d ms", tt.elapsed());
  //  scene->clear();
//affichage(ab,0,0,80,0);

}

void Dialog::on_pushButton_8_clicked()
{
    }

void Dialog::on_pushButton_5_clicked()
{
    QString a=ui->lineEdit_5->text();
    int aa=a.toInt();
    qDebug()<<"elt a supp : "<<aa;
    QTime t;
    t.start();
    av->supprimer(av,aa);
    av->reequilibre(av);
    setinfo();//tai=ab->nbrfeille(ab);

    qDebug("Time elapsed: %d ms", t.elapsed());
    scene2->clear();
affichage2(av,0,0,tai2*25,0);

}
