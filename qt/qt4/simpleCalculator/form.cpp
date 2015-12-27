#include "form.h"
#include <iostream>

Form::Form(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;

    lineEdit = new QLineEdit;
    browser = new QTextBrowser;

    layout->addWidget(browser);
    layout->addWidget(lineEdit);


    lineEdit->setPlaceholderText("Type an expression and press enter");
    lineEdit->setFocus();

    // old style
    connect(lineEdit, SIGNAL(returnPressed()), this, SLOT(updateUi()));

    setWindowTitle(tr("Calculator"));
    setLayout(layout);

}

Form::~Form()
{
}

void Form::updateUi()
{
//    string text = "";
//    try {
//        text = lineEdit.text();
//        browser.append("%s = <b>%s</b>", (text, ));
//    } catch {

//    }
    std::cout << "clicked" << std::endl;
}
