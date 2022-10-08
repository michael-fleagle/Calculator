#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    // this will include the "." button, and nums 0-9
    void NumPressed();
    // this will include the /, *, -, +, and ^
    void OperatorButtonPressed();
    // this will include the sin, cos, tan, cot, log, and ln
    void TrigButtonPressed(); // possible sepeartion in future
    // this will include the =
    void EqualButtonPressed();
    // this will include the +/-
    void ChangeSignButtonPressed();
    // this will include the Clear
    void ClearButtonPressed();
    // this will include the backspace
    void BackButtonPressed();
    // this will include {, }, (, and )
    void ParenButtonPressed(); // possible sepeartion in future
};
#endif // CALCULATOR_H
