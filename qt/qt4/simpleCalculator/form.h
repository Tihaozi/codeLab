#ifndef FORM_H
#define FORM_H

#include <QDialog>
#include <QTextBrowser>
#include <QLineEdit>
#include <QVBoxLayout>

class Form : public QDialog
{
    Q_OBJECT

public:
    Form(QWidget *parent = 0);
    ~Form();
public slots:
    void updateUi();

private:
    QVBoxLayout *layout;
    QTextBrowser *browser;
    QLineEdit *lineEdit;
};

#endif // FORM_H
