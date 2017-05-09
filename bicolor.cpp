#include "bicolor.h"
#include <stdlib.h>
#include <qdebug.h>

bicolor::bicolor()
{
}
////getter
///*
int bicolor::GetVal(){  return val;   }
bicolor bicolor::GetG(){  return *g;   }
bicolor bicolor::GetD(){  return *d;   }
//bicolor bicolor::Getbicolor(bicolor *a){  return *a;   }

////setter
void bicolor::SetVal(int vall){ val=vall;}
void bicolor::SetG(bicolor gg){ *g=gg;}
void bicolor::SetD(bicolor dd){ *d=dd;}
//*/

/*void bicolor::ajout(bicolor *&a,int x)
{
    if(a==NULL){bicolor *b=new bicolor();    b->d=NULL;  b->g=NULL;    b->val=x;    a=b;  }
    else if(x<a->val) {ajout (a->g, x);    }
    else ajout (a->d, x);
}*/
void bicolor::affichage_infixe ( bicolor *a )
{
    if (a!=NULL)
        {affichage_infixe(a->g );
        qDebug() <<a->GetVal();
        affichage_infixe(a->d );}
}
int bicolor::taille (bicolor *a)
{
if(a==NULL) return 0;
if (a->coul!=rouge)return 1;
int wt= taille(a->g)+taille(a->d);
//qDebug()<<"taille = "<< wt;
return wt;
}

void bicolor::rech_adj_bic(int x, bicolor *&z, bicolor *&q, bicolor *&t, bool &b)
{qDebug()<<"1";
    bicolor *p,*gp,*ggp,*a;
    a=t;    z->val=x;    b=false;p=t;gp=t;
    do{qDebug()<<"4";
        ggp=gp;gp=p;p=a;qDebug()<<"x = "<<x;//<<"a->val = "<<a->val;
        qDebug()<<"a = "<<t;//<<"a->val = "<<a->val;

        //qDebug()<<"a->g = "<<a->g->val<<"a->d"<<a->d->val;
        if(x<a->val)a=a->g;else a=a->d;
        qDebug()<<"a = "<<a->val;
        if((a->g)->coul==rouge && (a->d)->coul==rouge)
        {qDebug()<<"55";
            if(a==z)//adjonction
            {b=true;a=new bicolor;qDebug()<<"6";
                a->val=x;a->g=z;a->d=z;a->coul=rouge;
                if(x<p->val)p->g=a;else p->d=a;


            }
            else{qDebug()<<"7";
                a->coul=rouge;(*(*a).g).coul=blanc;
                a->d->coul=blanc;
            }
         if(p->coul==rouge){
          //rééquilibrage
             if(p->val>gp->val)//rg ou rdg
                 if(a->val>p->val)rg(gp);else rdg(gp);
                else //rd ou rgd
                 if(a->val<p->val)rd(gp);else ggp->d=gp;
             //retablir les couleur apres rotation
             qDebug()<<"8";
             gp->coul=blanc;(gp->g)->coul=rouge;(gp->d)->coul=rouge;
             //retablir la hierarchie des ascendants
             p=gp;gp=ggp;
             if(x==p->val)a=p;//a renvoit adr x ds t
             else if(x<p->val)a=p->g;else a=p->d;

         }

        }
    }while(x!=a->val);
    (t->d)->coul=blanc;
}


/*void bicolor::iteme ( bicolor *a )
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
        //bicolor *ab=NULL;
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
void bicolor::supmax(bicolor *&a,int &maxx)
{if(a->d!=NULL)supmax(a->d,maxx);
    else{maxx=a->val;
        bicolor *temp=a;
        a=a->g;
        //printf("supmax");
        free(temp);

    }
}
void bicolor::supprimer(bicolor *&a,int e)
{
    if(a!=NULL)
        {if(e<a->val) supprimer(a->g,e);
              else if(e>a->val) supprimer(a->d,e);
                else if(a->g!=NULL && a->d!=NULL){
                    int maxx ;supmax(a->g,maxx);
                    a->val=maxx;}
        else{
            bicolor *temp=a;
            if(a->g==NULL)a=a->d;
            else a=a->g;
            free(temp);
            }
        }
}
bool bicolor::recherche (bicolor *a,int x)
{
    bool temp;
    if(a==NULL) return false;
    else if(a->val==x)return true;
    else{
    temp= recherche(a->g,x);
    if(temp==false)temp= recherche(a->d,x);
}return temp;
}
///============///
void bicolor::rd(bicolor *&a)
{    bicolor *aux;
     aux=a->g;
    a->g=aux->d;
    aux->d=a;
    a=aux;}
///============///
void bicolor::rg(bicolor *&a)
{    bicolor *aux;
     aux=a->d;
    a->d=aux->g;
    aux->g=a;
    a=aux;}
///============///
void bicolor::rgd(bicolor *&a)
{rg(a->g);
rd(a);}
///============///
void bicolor::rdg(bicolor *&a)
{rd(a->g);
rg(a);}
