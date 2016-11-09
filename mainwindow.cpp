#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>//test



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Display->setText("");
    ui->RPN->setText("");
    saved = false;
    input = "";
    RPNtext = "";
    get[0] = &MainWindow::ifOpenParenthesis;
    get[1] = &MainWindow::ifClosedParenthesis;
    get[2] = &MainWindow::ifOperation;
    calc[0] = &MainWindow::power;
    calc[1] = &MainWindow::multiply;
    calc[2] = &MainWindow::divide;
    calc[3] = &MainWindow::add;
    calc[4] = &MainWindow::subtract;

    connect(ui->actionHelp, SIGNAL(triggered()), this, SLOT(help()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openMemory()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveMemory()));

    for (int i = 0; i < 26; ++i)
        mixedNum[i] = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDisplay(const QString &text)
{
    input += text;
    ui->Display->setText(input);
}

void MainWindow::updateRPN()
{
    ui->RPN->setText(RPNtext);
    stringstream ss;
    string tempRPN,junk;
    char memory;
    mixed num;
    qDebug()<<"input="<<input;//test
    tempRPN=normalize(input.toStdString());
    if(isalpha(tempRPN[0]) && tempRPN.find("=")!=string::npos)
    {
        ss<<tempRPN<<endl;
        ss>>memory>>junk;
        getline(ss,tempRPN);
    }
    getMemories(tempRPN);
    ss.clear();
    ss<<tempRPN<<endl;
    qDebug()<<"standard string="<<QString::fromStdString(tempRPN);//test
    while (ss.peek()!=10)
        ss>>p;
    toRPN(p.expression);
    getline(ss,junk);
    ss<<p<<endl;
    getline(ss,tempRPN);
    RPNtext=QString::fromStdString(tempRPN);
    qDebug()<<"RPNtext="<<RPNtext;//test
    num=calculateRPN(p.expression);
    ss<<num;
    if (memory)
    {
        qDebug()<<"Saving memory to="<<(int)memory-65;//test
        toMemory((int)memory-65, num);
    }
    getline(ss,tempRPN); //reads calculation as string
    qDebug()<<"RPNtext="<<RPNtext;//test
    RPNtext+="= " + QString::fromStdString(tempRPN); //adds calculation to RPNtext
    qDebug()<<"RPNtext="<<RPNtext;//test
    ui->RPN->setText(RPNtext);
    p.expression.clear();
}

bool MainWindow::checkAlpha()
{
    if ( input.size() >= 1 && ((input.cend()-1)->toLatin1() >= 65 && (input.cend()-1)->toLatin1() <= 90))
        return true;
    return false;
}

void MainWindow::getMemories(string& tempRPN)
{
    stringstream ss;
    string memo;
    int pos;
    while(tempRPN.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ")!=string::npos)
    {
        ss.clear();
        pos=tempRPN.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        ss<<getMemory((int)tempRPN[pos]-65);
        getline(ss,memo);
        qDebug()<<pos<<" "<<QString::fromStdString(memo);
        tempRPN.erase(pos,1);
        tempRPN.insert(pos,memo);
    }
}

void MainWindow::on_one_clicked()
{
    updateDisplay("1");
}

void MainWindow::on_two_clicked()
{
    updateDisplay("2");
}

void MainWindow::on_three_clicked()
{
    updateDisplay("3");
}

void MainWindow::on_four_clicked()
{
    updateDisplay("4");
}

void MainWindow::on_five_clicked()
{
    updateDisplay("5");
}

void MainWindow::on_six_clicked()
{
    updateDisplay("6");
}

void MainWindow::on_seven_clicked()
{
    updateDisplay("7");
}

void MainWindow::on_eight_clicked()
{
    updateDisplay("8");
}

void MainWindow::on_nine_clicked()
{
    updateDisplay("9");
}

void MainWindow::on_zero_clicked()
{
    updateDisplay("0");
}

void MainWindow::on_decimal_clicked()
{
    updateDisplay(".");
}

void MainWindow::on_negative_clicked()
{
    updateDisplay("-");
}

void MainWindow::on_divider_clicked()
{
    updateDisplay("/");
}

void MainWindow::on_plus_clicked()
{
    updateDisplay(" + ");
}

void MainWindow::on_subtract_clicked()
{
    updateDisplay(" - ");
}

void MainWindow::on_multiply_clicked()
{
    updateDisplay(" * ");
}

void MainWindow::on_divide_clicked()
{
    updateDisplay(" / ");
}

void MainWindow::on_power_clicked()
{
    updateDisplay(" ^ ");
}

void MainWindow::on_leftPar_clicked()
{
    updateDisplay("( ");
}

void MainWindow::on_rightPar_clicked()
{
    updateDisplay(" )");
}

void MainWindow::on_Enter_clicked()
{
    if (input == "")
    updateDisplay("");
    else
    {
        try
        {
            updateRPN();
        }
        catch (STACK_ERRORS)
        {
            p.expression.clear();
            RPNtext = "STACK ERROR";
            ui->RPN->setText(RPNtext);
        }
        catch (QUEUE_ERRORS)
        {
            RPNtext = "QUEUE ERROR";
            ui->RPN->setText(RPNtext);
        }

        catch (FRACTION_ERRS)
        {
            RPNtext = "FRACTION ERROR";
            ui->RPN->setText(RPNtext);
        }
        catch (CALC_ERROR)
        {
            RPNtext = "CALC ERROR";
            ui->RPN->setText(RPNtext);
        }
        catch (PARSER_ERR)
        {
            p.expression.clear();
            RPNtext = "SYNTAX ERROR";
            ui->RPN->setText(RPNtext);
        }
        input = "";
    }
}

// new functions imported

char MainWindow::norm(char ch)
{
    if (ch>96)
        return ch-=32;
    return ch;
}

string MainWindow::normalize(string str)
{
    size_t pos;
    while(str[str.length()-1]==' ')
        str.erase(str.length()-1,1);
    while((pos = str.find("--")) != string::npos)
        str.erase(pos,2);
    return str;
}

void MainWindow::ifOpenParenthesis(LinkedListStack<token>&oprs, LinkedListStack<token>&opds, token t)
{
    oprs.push(t);
}

void MainWindow::ifClosedParenthesis(LinkedListStack<token>&oprs, LinkedListStack<token>&opds, token t)
{
    while (!oprs.empty() && *(char*)oprs.top().getData()!='(')
        opds.push(oprs.pop());
    oprs.pop();
}

void MainWindow::ifOperation(LinkedListStack<token>&oprs, LinkedListStack<token>&opds, token t)
{
    while(!oprs.empty() && precedence(oprs.top())<= precedence(t))
        opds.push(oprs.pop());
    oprs.push(t);
}

int MainWindow::precedence(token t)
{
    size_t i = 0;
    string ops[4] = {"^","*/","+-","()"};
    while(ops[i++].find(*(char*)t.getData()) == string::npos);
    return i;
}

void MainWindow::toRPN(LinkedListQueue<token> &rpn)
{
    LinkedListStack<token> operands;
    LinkedListStack<token> operators;
    while (!rpn.empty())
    {
        if(!rpn.top().getType())
            operands.push(rpn.dequeue());
        else
            fromMemory(rpn,operands,operators);
    }
    while(!operators.empty())
    {
        if(*(char*)operators.top().getData()=='(')
            throw INVALID_EXPRESS;
        operands.push(operators.pop());
    }
    while(!operands.empty())
        operators.push(operands.pop());
    while(!operators.empty())
        rpn.push(operators.pop());
}

mixed MainWindow::power(mixed s,mixed t)
{
    return s^=t;
}

mixed MainWindow::multiply(mixed s,mixed t)
{
    return s*=t;
}

mixed MainWindow::divide(mixed s,mixed t)
{
    return s/=t;
}

mixed MainWindow::add(mixed s,mixed t)
{
    return s+=t;
}

mixed MainWindow::subtract(mixed s,mixed t)
{
    return s-=t;
}

mixed MainWindow::calculateRPN(LinkedListQueue<token>& rpn)
{
    int numOp=0, numMix=0;
    string ops="^*/+-";
    mixed m1, m2;
    LinkedListStack<mixed> operands;
    cout<<"rpn="<<rpn<<endl;
    while (!rpn.empty())
    {
        if (!rpn.top().getType())
        {
            operands.push(*(mixed*)rpn.dequeue().getData());
            numMix++;
        }
        else
        {
            int op=ops.find(*(char*)rpn.dequeue().getData());
            m2=operands.pop();
            checkEmpty(operands, m1);
            operands.push((this->*calc[op])(m1,m2));
            numOp++;
        }
    }
    if (operands.size()>1 || numMix-1!=numOp)
        throw INVALID_EXPRESS;
    return operands.top();
}

void MainWindow::checkEmpty(LinkedListStack<mixed>& operands, mixed &m1)
{
    if (!operands.empty())
        m1=operands.pop();
}

void MainWindow::toMemory(int index, mixed num)
{
    if(index<26)
        mixedNum[index] = num;
}

mixed MainWindow::getMemory(int index)
{
    if(index<26)
        return mixedNum[index];
    else
        throw INVALID_EXPRESS;
}

void MainWindow::deleteMemory(int index)
{
    if(index<26)
        mixedNum[index] = 0;
}

void MainWindow::clearMemory()
{
    for(int i=0; i<26; i++)
        mixedNum[i]=0;
}

void MainWindow::fromMemory(LinkedListQueue<token> &rpn, LinkedListStack<token> &operands, LinkedListStack<token> &operators)
{
    string ops[3] = {"(",")","^*/+-"};
    if(isalpha(*(char*)rpn.top().getData()))
        operands.push(token(new mixed(getMemory((int)*(char*)rpn.dequeue().getData()-65)),0));
    else
    {
        size_t i = string::npos;
        while(ops[++i].find(*(char*)rpn.top().getData()) == string::npos);
        (this->*get[i])(operators,operands,rpn.dequeue());
    }
}

void MainWindow::empty()
{
    return;
}

void MainWindow::help()
{
    DialogHelp hDialog;
    hDialog.setModal(true);
    hDialog.exec();
    //QMessageBox::information(this, "Help Contents", message);
}

void MainWindow::saveMemory()
{
    QString saveDestination = QFileDialog::getSaveFileName(this, tr("Save Memories As..."),
                                                                   QDir::currentPath(), tr("(*.mlst)"));
    string normal = saveDestination.toStdString();
    cout<<"normal="<<normal<<endl;
    ofstream fs (normal.c_str());
    for (int i = 0; i < 26; ++i)
        fs<<mixedNum[i]<<endl;
    fs.close();
    saved = true;
}

void MainWindow::openMemory()
{
    QString loadWhat = QFileDialog::getOpenFileName(this, tr("Open Memories..."),
                                                    QDir::homePath(), tr("(*.mlst)"));
    string normal = loadWhat.toStdString();
    cout<<"normal="<<normal<<endl;
    stringstream ss;
    ifstream fs (normal.c_str());
    for (int i = 0; i < 26; ++i)
    {
        try
        {
            getline(fs, normal);
            cout<<"normal="<<normal<<endl;
            ss<<normal;
            ss>>(mixedNum[i]);
            ss.clear();
            ss.str("");
        }
        catch(FRACTION_ERRS)
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","The Fraction was either manipulated or handtyped\nSetting this fraction to 0");
            messageBox.setFixedSize(500,200);
            mixedNum[i] = 0;
        }
    }
    fs.close();
}

void MainWindow::on_clear_clicked()
{
    input = "";
    ui->Display->setText(input);
    RPNtext = "";
    ui->RPN->setText((RPNtext));
}

void MainWindow::on_split_clicked()
{
    updateDisplay(" ");
}

void MainWindow::on_Backspace_clicked()
{
    if ((*(input.cend()-2) == '-' && *(input.cend()-1) == ' ') || *(input.cend()-2) == '*'
         || *(input.cend()-2) == '+' || *(input.cend()-2) == '/' || *(input.cend()-2) == '^'
         || *(input.cend()-2) == '(' || *(input.cend()-2) == ')' || *(input.cend()-2) == '=' )
        input.chop(3);
    else
        input.chop(1);
    ui->Display->setText(input);
}

void MainWindow::on_MemoryA_clicked()
{
    checkAlpha() ? empty() : updateDisplay("A");
}

void MainWindow::on_MemoryB_clicked()
{
    checkAlpha() ? empty() : updateDisplay("B");
}

void MainWindow::on_MemoryC_clicked()
{
    checkAlpha() ? empty() : updateDisplay("C");
}

void MainWindow::on_MemoryD_clicked()
{
    checkAlpha() ? empty() : updateDisplay("D");
}

void MainWindow::on_MemoryE_clicked()
{
    checkAlpha() ? empty() : updateDisplay("E");
}

void MainWindow::on_MemoryF_clicked()
{
    checkAlpha() ? empty() : updateDisplay("F");
}

void MainWindow::on_MemoryG_clicked()
{
    checkAlpha() ? empty() : updateDisplay("G");
}

void MainWindow::on_MemoryH_clicked()
{
    checkAlpha() ? empty() : updateDisplay("H");
}

void MainWindow::on_MemoryI_clicked()
{
    checkAlpha() ? empty() : updateDisplay("I");
}

void MainWindow::on_MemoryJ_clicked()
{
    checkAlpha() ? empty() : updateDisplay("J");
}

void MainWindow::on_MemoryK_clicked()
{
    checkAlpha() ? empty() : updateDisplay("K");
}

void MainWindow::on_MemoryL_clicked()
{
    checkAlpha() ? empty() : updateDisplay("L");
}

void MainWindow::on_MemoryM_clicked()
{
    checkAlpha() ? empty() : updateDisplay("M");
}

void MainWindow::on_MemoryN_clicked()
{
    checkAlpha() ? empty() : updateDisplay("N");
}

void MainWindow::on_MemoryO_clicked()
{
    checkAlpha() ? empty() : updateDisplay("O");
}

void MainWindow::on_MemoryP_clicked()
{
    checkAlpha() ? empty() : updateDisplay("P");
}

void MainWindow::on_MemoryQ_clicked()
{
    checkAlpha() ? empty() : updateDisplay("Q");
}

void MainWindow::on_MemoryR_clicked()
{
    checkAlpha() ? empty() : updateDisplay("R");
}

void MainWindow::on_MemoryS_clicked()
{
    checkAlpha() ? empty() : updateDisplay("S");
}

void MainWindow::on_MemoryT_clicked()
{
    checkAlpha() ? empty() : updateDisplay("T");
}

void MainWindow::on_MemoryU_clicked()
{
    checkAlpha() ? empty() : updateDisplay("U");
}

void MainWindow::on_MemoryV_clicked()
{
    checkAlpha() ? empty() : updateDisplay("V");
}

void MainWindow::on_MemoryW_clicked()
{
    checkAlpha() ? empty() : updateDisplay("W");
}

void MainWindow::on_MemoryX_clicked()
{
    checkAlpha() ? empty() : updateDisplay("X");
}

void MainWindow::on_MemoryY_clicked()
{
    checkAlpha() ? empty() : updateDisplay("Y");
}

void MainWindow::on_MemoryZ_clicked()
{
    checkAlpha() ? empty() : updateDisplay("Z");
}

void MainWindow::on_memoryclear_clicked()
{
    clearMemory();
    RPNtext = "All Memories Cleared";
    ui->RPN->setText(RPNtext);
    RPNtext = "";
}

void MainWindow::on_memoryErase_clicked()
{
    QStringList items;
    items << tr("A") << tr("B") << tr("C") << tr("D") << tr("E") << tr("F") << tr("G") << tr("H") << tr("I") << tr("J") << tr("K") << tr("L") << tr("M") << tr("N") << tr("O") << tr("P") << tr("Q") << tr("R")  << tr("S") << tr("T") << tr("U") << tr("V") << tr("W") << tr("X") << tr("Y") << tr("Z");

    bool ok;
    QString item = QInputDialog::getItem(this, tr("Erase Which Memory?"),
                                         tr("Memory:"), items, 0, false, &ok);
    if (ok && !item.isEmpty())
    {
        qDebug()<<item;//test
        QChar ch = item.at(0);
        int memory = ch.toLatin1() - 65;
        qDebug()<<memory;
        deleteMemory(memory);
    }
    RPNtext = "Memory Cleared";
    ui->RPN->setText(RPNtext);
    RPNtext = "";
}

void MainWindow::on_equals_clicked()
{
    if (input.size() != 1 || (!isalpha(input.at(0).toLatin1())) )
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","The equals can only be used once and only one letter can be present");
        messageBox.setFixedSize(500,200);
    }
    else
        updateDisplay(" = ");
}

void MainWindow::closeEvent(QCloseEvent *)
{
    if (!saved)
    {
        QMessageBox::StandardButton messageBox;
        messageBox = QMessageBox::question(this, "Save", "Do you want to save your Memories?",
                                        QMessageBox::Yes|QMessageBox::No);
        (messageBox == QMessageBox::Yes) ? saveMemory() : empty();
    }
    QMainWindow::close();
}
