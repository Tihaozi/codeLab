#include <QApplication>
//#include <QWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    QWidget widget;
//    widget.show();

    QPushButton button("Hello world");
    button.show();

    return app.exec();
}

