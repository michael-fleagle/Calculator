// Michael Fleagle
// CS480

#include "calculator.h"
#include "./ui_calculator.h"

// create value to hold current calculation
double calcVal = 5.0;

//

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    // show the text in the UI Display
    ui->Display->setText(QString::number(calcVal));
}

Calculator::~Calculator()
{
    delete ui;
}

