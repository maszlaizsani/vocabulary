#include "vocabulary.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vocabulary w;
    w.show();

    return a.exec();
}
