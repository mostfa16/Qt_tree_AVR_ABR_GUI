#include "avl.h"
#include <stdlib.h>
#include <qdebug.h>

avl::avl()
{racine=NULL;
}

///========///
/// getter ///
///========///
int avl::GetVal(){  return val;   }
int avl::GetDes(){  return des;   }
avl avl::GetG(){  return *g;   }
avl avl::GetD(){  return *d;   }


///========///
/// setter ///
///========///
void avl::SetVal(int vall){ val=vall;}
void avl::SetDes(int dess){ des=dess;}
void avl::SetG(avl gg){ *g=gg;}
void avl::SetD(avl dd){ *d=dd;}
///============///
/// \brief avl::ajout
/// \param t
/// \param e
///
void avl::affichage_infixe ( avl *a )
{
    if (a!=NULL)
        {affichage_infixe(a->g );
        qDebug() <<a->GetVal();
        affichage_infixe(a->d );}
}

void avl::ajout(avl *&t,int e)
{avl *y=new avl();
//y->SetVal(e);y->SetG(NULL);y->SetG(NULL);y->des=0;
    y->val=e;y->g=NULL;y->d=NULL;y->des=0;
if(t==NULL){t=y;return;}
avl *p,*pp,*aa,*a;
p=t;pp=NULL;a=t;aa=NULL;
while(p!=NULL)
            {
            if(p->des!=0){
                        aa=pp;a=p;
                        }
            pp=p;//qDebug()<<"e= "<<e<<"pval="<<p->val;
            if(e>p->val){p=p->d;}
            else        {p=p->g;}
}
            if(e>pp->val){pp->d=y;}
            else        {pp->g=y;}

            p=a;
            while(p!=y){//qDebug()<<"1";
                    if(e>p->val){
                            p->des--;
                            p=p->d;
//affichage_infixe(t);
                    }
                    else{
                            p->des++;
                            p=p->g;

                        }
                       }

//qDebug()<<"des d = "<<(a->d)->val;
switch(a->des)
{case -1:case 0:case 1:return;

case -2:switch((a->d)->des)
    {
    case -1:rg(a);
    a->des=0;
    (a->g)->des=0;
    break;
    case 1:
        rdg(a);
            switch(a->des)
            {
            case 1:
                    (a->d)->des=0;
                    a->g->des=1;break;
            case -1:
                    (a->d)->des=-1;
                    (a->g)->des=0;break;
            case 0:{
                    (a->d)->des=0;
                    (a->g)->des=0;break;
            }
            }break;

    }

case 2:switch((a->g)->des)
    {
    case 1:rd(a);
        a->des=0;

        (a->d)->des=0;

        break;
    case -1:
        rgd(a);
            switch(a->des)
            {case 1:(a->g)->des=0;
            (a->d)->des=-1;break;//qDebug()<<"n";
            case -1:(a->g)->des=1;//qDebug()<<"o";
            (a->d)->des=0;break;
            case 0:{(a->g)->des=0;//qDebug()<<"q";
            (a->d)->des=0;break;
            }
            }break;
    }
}//}
//qDebug()<<"aa= "<<aa->val;
if(aa==NULL){t=a;}
else if(a->val>aa->val){aa->d=a;}
     else {aa->g=a;}
//qDebug()<<"s";//*/
//
}

///============///
int avl::taille (avl *a)
{
if(a==NULL) return 0;
else{
int wt= 1+taille(a->g)+taille(a->d);
//qDebug()<<"taille = "<< wt;
return wt;}
}
///============///
/*void avl::iteme ( avl *a )
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
        //avl *ab=NULL;
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
void avl::supmax(avl *&a,int &maxx)
{if(a->d!=NULL)supmax(a->d,maxx);
    else{maxx=a->val;
        avl *temp=a;
        a=a->g;
        //printf("supmax");
        free(temp);

    }
}
void avl::supprimer(avl *&a,int e)
{
    if(a!=NULL)
        {if(e<a->val) supprimer(a->g,e);
              else if(e>a->val) supprimer(a->d,e);
                else if(a->g!=NULL && a->d!=NULL){
                    int maxx ;supmax(a->g,maxx);
                    a->val=maxx;}
        else{
            avl *temp=a;
            if(a->g==NULL)a=a->d;
            else a=a->g;
            free(temp);
            }
        }
}
///============///
bool avl::recherche (avl *a,int x)
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
void avl::rd(avl *&a)
{    avl *aux;
     aux=a->g;
    a->g=aux->d;
    aux->d=a;
    a=aux;}
///============///
void avl::rg(avl *&a)
{    avl *aux;
     aux=a->d;
    a->d=aux->g;
    aux->g=a;
    a=aux;}
///============///
void avl::rgd(avl *&a)
{rg(a->g);
rd(a);}
///============///
void avl::rdg(avl *&a)
{rd(a->d);
rg(a);}
///////////////////////
///////////////////////
int avl::compareTo(int x,int y){
    if(x==y)return 0;
    if(x<y)return -1;
    return 1;

}
void avl::ajouter ( int x){
//    qDebug()<<"ajouter";
    ajoutAVL( racine, NULL, true, x);
}
bool avl::ajoutAVL(avl *&r, avl *p, bool g, int e){//qDebug()<<"ajoutavl"<<r;
   if(r == NULL) {qDebug()<<"0";
       r = new avl;r->val=e;r->g=NULL;r->d=NULL;r->des=0;//qDebug()<<"2";
       if (p == NULL) {}//racine  = r;
    //   qDebug()<<"3";}
       else if(g) {p->g = r;}
      // qDebug()<<"4";}
            else  p->d = r;
     //  qDebug()<<"5";
       return true;
      // qDebug()<<"if r == null";
   }else{
      // qDebug()<<"if r!=NULL";
      int a = compareTo(e,r->val);
      //if (a==0) return false;// a déjà présent dans l'arbre
      if (a<0)
          if(ajoutAVL(r->g, r, true, e)) return equilibreG(r, p, g);
          else return false;
      else
          if(ajoutAVL(r->d, r, false, e)) return equilibreD(r, p, g);
          else return false;
   }
}
bool avl::equilibreD ( avl *r, avl *p, bool g){
   // r est le fils gauche de p si g vaut true, r est le fils droit de p si g vaut false
   // retourne true si après équilibrage l'arbre a grandi
  avl *r1, *r2;
  switch(r->des){
      case -1 : r->des = 0; return false;
      case  0 : r->des = 1; return true;
      case  1 :
      default : r1 = r->d;
            if(r1->des == 1){qDebug()<<"des=1";
           r->d = r1->g; r1->g = r;
           r->des = 0;
           r = r1 ;
        }else{qDebug()<<"des not1";
           r2 = r1->g; r1->g = r2->d;
           r2->d = r1;
           r->d = r2->g; r2->g = r;qDebug()<<"desf";
           if(r2->des == 1) r->des = -1;
           else                  r->des = 0;
           if(r2->des == -1) r1->des = 1;
           else                   r1->des = 0;
           r = r2;
        }
        // refaire le chaînage avec le père
        if(p==NULL) r=p;//qDebug()<<"p null faire rien";//racine = r;
        else if( g ) p->g = r ;
             else p->d = r ;
        r->des = 0;
        return false;
   }
}
bool avl::equilibreG (avl *r, avl *p, bool g){
     // r est le fils gauche de p si g vaut  true, r est le fils droit de p si g vaut false
     // retourne true si après équilibrage l'arbre a grandi
     avl *r1, *r2;
     switch (r->des){
         case 1 : r->des=0; return false;
         case 0 : r->des = -1; return true;
         case -1 :
         default : r1 = r->g;
         if(r1->des==-1){
            r->g = r1->d; r1->d= r;
            r->des = 0; r = r1;
         }else{
            r2 = r1->d; r1->d = r2->g; r2->g=r1;
            r->g=r2->d; r2->d = r;
            if(r2->des == -1) r->des = 1;
            else               r->des = 0;
            if(r2->des == 1) r1->des =-1;
            else               r1->des = 0;
            r=r2;
       }
       // refaire le chaînage avec le père
       if (p == NULL) ;//racine = r;
       else if( g ) p->g = r ;
            else     p->d = r ;
       r->des = 0;
       return false;
   }
}
int avl::nbrfeille(avl *a)
{
    int nb;
    if(a==NULL)nb=0;
    else
    if(a->g==NULL && a->d==NULL)nb=1;
    else
    nb=nbrfeille(a->g)+nbrfeille(a->d);
    return nb;
}
int avl::hauteurA(avl *a){
    if(a==NULL)return -1;
    int h1=hauteurA(a->g);if(h1==-2)return -2;
    int h2=hauteurA(a->d);if(h2==-2)return -2;
    if(h1>h2)
        if(h1>h2+1)return -2;
        else return h1+1;
    else if(h2>h1+1)return -2;
        else return h2+1;
}
void avl::reequilibre(avl *t){
    avl *p,*pp,*aa,*a;
    p=t;pp=NULL;a=t;aa=NULL;
    if(t!=NULL){
        reequilibre(t->d);
        t->des=hauteurA(t->d)-hauteurA(t->g);
        reequilibre(t->g);
    }

}
