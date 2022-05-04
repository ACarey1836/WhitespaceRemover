#include "extrawhitespaceeliminator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExtraWhiteSpaceEliminator w;
    w.show();
    return a.exec();
}
