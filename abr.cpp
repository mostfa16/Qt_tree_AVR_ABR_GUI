#include "abr.h"
#include <stdlib.h>
#include <qdebug.h>

abr::abr()
{

}
///========///
/// getter ///
///========///
int abr::GetVal(){  return val;   }
abr abr::GetG(){  return *g;   }
abr abr::GetD(){  return *d;   }


///========///
/// setter ///
///========///
void abr::SetVal(int vall){ val=vall;}
void abr::SetG(abr gg){ *g=gg;}
void abr::SetD(abr dd){ *d=dd;}


///========///
///methodes///
///========///
void abr::ajout(abr *&a,int x)
{
    if(a==NULL){abr *b=new abr();    b->d=NULL;  b->g=NULL;    b->val=x;    a=b;  }
    else if(x<a->val) {ajout (a->g, x);    }
    else ajout (a->d, x);


}
void abr::affichage_infixe ( abr *a )
{
    if (a!=NULL)
        {affichage_infixe(a->g );
        qDebug() <<a->GetVal();
        affichage_infixe(a->d );}
}
int abr::taille (abr *a)
{
if(a==NULL) return 0;
else{
int wt= 1+taille(a->g)+taille(a->d);
//qDebug()<<"taille = "<< wt;
return wt;}
}
/*void abr::iteme ( abr *a )
{
    if (a!=NULL)
        {iteme(a->g );
        //qDebug() <<a->val;
        addItem(MySquare::square);

        square=new MySquare();
        //square2=new MySquare();

        QGraphicsTextItem * io = new QGraphicsTextItem;
        io->setPos(15,15);
        //int sss=ab->getval();
        //abr *ab=NULL;
          //      ab->ajout(*&ab,499);
            //    ab->ajout(*&ab,88);
              //  ab->ajout(*&ab,887);
                //ab->affichage_infixe ( ab );
        int i=ab->GetVal();
        QString s = QString::number(i);
        io->setPlainText(s);

        scene->addItem(io);
        scene->addItem(square);
        iteme(a->d );}
}
*/
void abr::supmax(abr *&a,int &maxx)
{if(a->d!=NULL)supmax(a->d,maxx);
    else{maxx=a->val;
        abr *temp=a;
        a=a->g;
        //printf("supmax");
        free(temp);

    }
}
void abr::supprimer(abr *&a,int e)
{
    if(a!=NULL)
        {if(e<a->val) supprimer(a->g,e);
              else if(e>a->val) supprimer(a->d,e);
                else if(a->g!=NULL && a->d!=NULL){
                    int maxx ;supmax(a->g,maxx);
                    a->val=maxx;}
        else{
            abr *temp=a;
            if(a->g==NULL)a=a->d;
            else a=a->g;
            free(temp);
            }
        }
}
bool abr::recherche (abr *a,int x)
{
    bool temp;
    if(a==NULL) return false;
    else if(a->val==x)return true;
    else{
    temp= recherche(a->g,x);
    if(temp==false)temp= recherche(a->d,x);
}return temp;
}
int abr::hauteur (abr *a)
{int h1,h2;
    if(a==NULL)
        return -1;
    else
        {h1=hauteur(a->g);
        h2=hauteur(a->d);
        if(h1>h2) return h1+1;
        else return h2+1;
        }
}
int abr::nbrfeille(abr *a)
{
    int nb;
    if(a==NULL)nb=0;
    else
    if(a->g==NULL && a->d==NULL)nb=1;
    else
    nb=nbrfeille(a->g)+nbrfeille(a->d);
    return nb;
}
