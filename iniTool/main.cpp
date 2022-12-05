#include "iniTool.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    iniTool w;
    w.show();
    return a.exec();
}
