#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include <QString>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fraction.h>
#include <mixed.h>
#include <parser.h>
#include <token.h>
#include <string>
#include <linkedlistqueue.h>
#include <linkedliststack.h>
#include <typeinfo>
#include <QFileDialog>
#include <QDir>
#include <QTableWidget>
#include "dialoghelp.h"
#include <QInputDialog>
#include <QMessageBox>

enum CALC_ERROR {INVALID_EXPRESS};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_one_clicked();

    void on_two_clicked();

    void on_three_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_zero_clicked();

    void on_decimal_clicked();

    void on_negative_clicked();

    void on_divider_clicked();

    void on_plus_clicked();

    void on_subtract_clicked();

    void on_multiply_clicked();

    void on_divide_clicked();

    void on_power_clicked();

    void on_leftPar_clicked();

    void on_rightPar_clicked();

    void on_Enter_clicked();

    void on_clear_clicked();

    void updateDisplay(const QString &text);

    void on_split_clicked();

    void on_Backspace_clicked();

    void on_MemoryA_clicked();

    void on_MemoryB_clicked();

    void on_MemoryC_clicked();

    void on_MemoryD_clicked();

    void on_MemoryE_clicked();

    void on_MemoryF_clicked();

    void on_MemoryG_clicked();

    void on_MemoryH_clicked();

    void on_MemoryI_clicked();

    void on_MemoryJ_clicked();

    void on_MemoryK_clicked();

    void on_MemoryL_clicked();

    void on_MemoryM_clicked();

    void on_MemoryN_clicked();

    void on_MemoryO_clicked();

    void on_MemoryP_clicked();

    void on_MemoryQ_clicked();

    void on_MemoryR_clicked();

    void on_MemoryS_clicked();

    void on_MemoryT_clicked();

    void on_MemoryU_clicked();

    void on_MemoryV_clicked();

    void on_MemoryW_clicked();

    void on_MemoryX_clicked();

    void on_MemoryY_clicked();

    void on_MemoryZ_clicked();

    void help();

    void saveMemory();

    void openMemory();

    void on_memoryclear_clicked();

    void on_memoryErase_clicked();

    void on_equals_clicked();

private:
    Ui::MainWindow *ui;
    QString input;
    QString RPNtext;
    bool saved;
    bool negative;
    bool fraction;
    parser p;
    mixed mixedNum[26];

    void updateRPN();
    bool checkAlpha();
    //converts lower to uppercase in char
    char norm(char ch);
    //converts lower to uppercase in string
    string normalize(string str);
    //pushes to operator if (
    void ifOpenParenthesis(LinkedListStack<token>&,LinkedListStack<token>&,token);
    //pushes operators to operands between ( and )
    void ifClosedParenthesis(LinkedListStack<token>&,LinkedListStack<token>&,token);
    //checks precedence and pushes to operand accordingly
    void ifOperation(LinkedListStack<token>&,LinkedListStack<token>&,token);
    //checks operator precedence
    int precedence(token t);
    //converts exp to rpn and saves to queue
    void toRPN(LinkedListQueue<token>&);
    mixed power(mixed s,mixed t);
    mixed multiply(mixed s,mixed t);
    mixed divide(mixed s,mixed t);
    mixed add(mixed s,mixed t);
    mixed subtract(mixed s,mixed t);
    //calculates rpn and returns the ans
    mixed calculateRPN(LinkedListQueue<token>&);
    //writes to memory at index
    void toMemory(int index, mixed num);
    //retrieves memories & replaces them in expression
    void getMemories(string& tempRPN);
    //gets memory at index
    void fromMemory(LinkedListQueue<token> &rpn, LinkedListStack<token> &operands, LinkedListStack<token> &operators);
    void checkEmpty(LinkedListStack<mixed> &operands, mixed &m1);
    void empty();
    mixed getMemory(int index);
    //deletes memory at index
    void deleteMemory(int index);
    //clears all memories
    void clearMemory();
    //get[3] deals with different operators accordingly
    void (MainWindow::*get[3])(LinkedListStack<token>&,LinkedListStack<token>&,token);
    //calc[5] performs operations
    mixed (MainWindow::*calc[5])(mixed,mixed); //={&power,&multiply,&divide,&add,&subtract};

    void closeEvent(QCloseEvent *);

};

#endif // MAINWINDOW_H
