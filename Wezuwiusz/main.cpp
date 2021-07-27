#include "screen_welcome.hh"
#include <QApplication>
#include <QSurfaceFormat>
#include "scene.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Screen_Welcome w;
    w.show();

    return a.exec();
}
