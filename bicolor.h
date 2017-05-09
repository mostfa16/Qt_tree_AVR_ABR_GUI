#include "abr.h"
#ifndef BICOLOR_H
#define BICOLOR_H
typedef enum{rouge,blanc}couleur;
class bicolor //: public abr
{
public:
    bicolor();
    int GetVal();
    bicolor GetG();
    bicolor GetD();
    void SetVal(int vall);
    void SetG(bicolor gg);
    void SetD(bicolor dd);
    int taille (bicolor *a);
    void rech_adj_bic(int e,bicolor *&z,bicolor *&q,bicolor *&t,bool &b);
    void affichage_infixe ( bicolor *a );
    void supmax(bicolor *&a,int &maxx);
    void supprimer(bicolor *&a,int e);
    bool recherche (bicolor *a,int x);
    void rd(bicolor *&a);
    void rg(bicolor *&a);
    void rgd(bicolor *&a);
    void rdg(bicolor *&a);
//protected:
        int val;
        bicolor *d,*g;
        couleur coul;
};

#endif // BICOLOR_H
