#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QtMath>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = 0);
    ~Calculator();

private:
    Ui::Calculator *ui;
    void shuntingYard();
    bool isOperator(QString data);
    int precedence(QString data);

private slots:
    // this will include the "." button, and nums 0-9
    void NumPressed();
    // this will include the /, *, -, +, ^, sin, cos, tan, cot, log, ln, {, }, (, and )
    void OperatorButtonPressed();
    // this will include the =
    void EqualButtonPressed();
    // this will include the +/-
    void ChangeSignButtonPressed();
    // this will include the Clear
    void ClearButtonPressed();
    // this will include the backspace
    void BackButtonPressed();
};
#endif // CALCULATOR_H
