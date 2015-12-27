#include <QApplication>
//#include <QWidget>
#include <QPushButton>

#include "widget.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // using QWidget Class and create a window
//    QWidget widget;
//    widget.show();

    // using QPushButton Class and create a button at the center of window
//    QPushButton button("Hello world");
//    button.show();

    // using widget.h header file for creating window
    Widget w;
    w.show();

    return app.exec();
}

