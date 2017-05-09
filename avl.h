#include "abr.h"
#ifndef AVL_H
#define AVL_H

class avl //: public abr
{
public:
    avl();
    int GetVal();
    int GetDes();
    avl GetG();
    avl GetD();
    void SetVal(int vall);
    void SetG(avl gg);
    void SetD(avl dd);
    void SetDes(int dess);
    int  taille(avl *a);
    void affichage_infixe ( avl *a );
    void ajout(avl *&t,int e);
    void supmax(avl *&a,int &maxx);
    void supprimer(avl *&a,int e);
    bool recherche (avl *a,int x);
    void rd(avl *&a);
    void rg(avl *&a);
    void rgd(avl *&a);
    void rdg(avl *&a);

    int  compareTo(int x,int y);
    void ajouter ( int x);
    bool ajoutAVL(avl *&r, avl *p, bool g, int e);
    bool equilibreD ( avl *r, avl *p, bool g);
    bool equilibreG ( avl *r, avl *p, bool g);
    int nbrfeille(avl *a);
    int hauteurA(avl *a);
    void reequilibre(avl *a);
//protected:
        int val;
        avl *d,*g;
        int des;
    avl *racine=NULL;
};


#endif // AVL_H
