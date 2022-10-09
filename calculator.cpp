// Michael Fleagle
// CS480

#include "calculator.h"
#include "./ui_calculator.h"

// add Qt math to handle match functions and vectors to use in place of arrays
#include <QtMath>
#include <vector>

// namesapce std for ease of use
using namespace std;

// create value to hold current calculation value
double calcVal = 0.0;

// create two vectors to hold the output and operator stack
vector<double> output;
vector<QString> operators;
vector<QString> input;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    // All code above this is generated by the Qt creator software //

    // show the text in the UI Display
    ui->Display->setText(QString::number(calcVal));

    // set up buttons for numbers
    QPushButton *numButtons[10];
    for(int i = 0; i < 10; i++)
    {
        QString buttonName = "Button_" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(buttonName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }

    // set up + button
    connect(ui->Button_Plus, SIGNAL(released()), this, SLOT(OperatorButtonPressed()));

    // set up - button
    connect(ui->Button_Min, SIGNAL(released()), this, SLOT(OperatorButtonPressed()));

    // set up * button
    connect(ui->Button_Mult, SIGNAL(released()), this, SLOT(OperatorButtonPressed()));

    // set up / button
    connect(ui->Button_Div, SIGNAL(released()), this, SLOT(OperatorButtonPressed()));

    // set up ^ button
    connect(ui->Button_Pow, SIGNAL(released()), this, SLOT(OperatorButtonPressed()));

    // set up sin button
    // set up cos button
    // set up tan button
    // set up cot button
    // set up ln button
    // set up log button

}

Calculator::~Calculator()
{
    delete ui;
}

// method to handle a number button press
void Calculator::NumPressed()
{
    QPushButton *button = (QPushButton *)sender();
    QString buttonValue = button->text();
    QString displayValue = ui->Display->text();

    // if the current display is 0, update to be the new number input
    if((displayValue.toDouble() == 0) || (displayValue.toDouble() == 0.0))
    {
        // set the dispaly to show the newly pressed value
        ui->Display->setText(buttonValue);
    }
    else
    {
        // if the current display value is not 0, add the number pressed to the value
        QString newValue = displayValue + buttonValue;
        double newValDbl = newValue.toDouble();
        ui->Display->setText(QString::number(newValDbl, 'g', 20));
    }
}

// method to handle an operator button press +, -, *, /
void Calculator::OperatorButtonPressed()
{
    // reset all trigger flags to false
    bool addTrigger = false;
    bool minTrigger = false;
    bool multTrigger = false;
    bool divTrigger = false;
    bool powTrigger = false;

    // store current value in the display
    QString displayValue = ui->Display->text();
    calcVal = displayValue.toDouble();

    // figure out what button was pushed
    QPushButton *button = (QPushButton *)sender();
    QString buttonValue = button->text();

    // if statements to prin the correct operator to the screen and set the trigger flag
    if(QString::compare(buttonValue, "+", Qt::CaseInsensitive) == 0)
    {
        // set the flag for that operation to true
        addTrigger = true;
    }
    else if(QString::compare(buttonValue, "-", Qt::CaseInsensitive) == 0)
    {
        // set the flag for that operation to true
        minTrigger = true;
    }
    else if(QString::compare(buttonValue, "*", Qt::CaseInsensitive) == 0)
    {
        // set the flag for that operation to true
        multTrigger = true;
    }
    else if(QString::compare(buttonValue, "/", Qt::CaseInsensitive) == 0)
    {
        // set the flag for that operation to true
        divTrigger = true;
    }
    else if(QString::compare(buttonValue, "^", Qt::CaseInsensitive) == 0)
    {
        // set the flag for that operation to true
        powTrigger = true;
    }

    // clear the display ?? do I want to do this?
    ui->Display->setText(displayValue + " " + buttonValue);
}

// method to handle the press of the equal button
// method will call shunting yard algorithm for current input
void Calculator::EqualButtonPressed()
{
    // double to hold the solution to the math
    double solution = 0.0;

    // get the current display value from the display
    QString displayValue = ui->Display->text();

    // convert string to double
    double curDisplayValue = displayValue.toDouble();

}
































