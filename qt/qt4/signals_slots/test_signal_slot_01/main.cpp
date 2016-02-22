#include <iostream>
#include <QApplication>
#include <QPushButton>
using namespace std;

// SLOT
void sayHello()
{
    cout << "Hello World!" << endl;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton button('Hello');

    // SIGNALS
    connect(button, SIGNAL(clicked), this, SLOT(sayHello()));

    button.show();

    return app.exec();
}
