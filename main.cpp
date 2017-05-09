#include "dialog.h"
#include <QApplication>
#include <qdebug.h>
//#include <abr.h>
//#include <text.h>
//*ab=NULL;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Dialog w;
    //w.showMaximized();

    w.show();
    w.setWindowTitle("Les Arbres 1.8.1 (Boudjema M.A)");
    return a.exec();

}
