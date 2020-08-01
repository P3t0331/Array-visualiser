#include "arraywindow.h"
#include <QMainWindow>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    arrayWindow w;
    w.show();

    return a.exec();
}
