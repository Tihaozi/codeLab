#include "form.h"
#include <iostream>

Form::Form(QWidget *parent) : QDialog(parent)
{
    layout = new QVBoxLayout;

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
    delete lineEdit;
    delete browser;
}

void Form::updateUi()
{
    QString text = lineEdit->text();
    browser->append(QString("%1 = <b>%2</b>").arg(text).arg(text));
}
