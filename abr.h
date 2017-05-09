//#include "mysquare.h"

#include <QTime>
#ifndef ABR_H
#define ABR_H

class abr
{
public:
    abr();
    int GetVal();
    abr GetG();
    abr GetD();
    void SetVal(int vall);
    void SetG(abr gg);
    void SetD(abr dd);
    int taille (abr *a);
    void ajout(abr *&a,int x);
    void affichage_infixe ( abr *a );
    void supmax(abr *&a,int &maxx);
    void supprimer(abr *&a,int e);
    bool recherche (abr *a,int x);
    int hauteur (abr *a);
    int nbrfeille(abr *a);

//protected:
        int val;
        abr *d,*g;
};

#endif // ABR_H
