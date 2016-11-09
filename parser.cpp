#include "parser.h"
#include <QtDebug>//test
#include <QString>//test

parser::parser()
{
}

parser::~parser()
{
}

parser& parser::operator=(const parser &other)
{
    expression=other.expression;
    return *this;
}

void parser::getOp(istream &in, char input)
{
    if(input=='-'&&in.peek()!=' ')
    {
        getMixed(in,input);
        return;
    }
    qDebug()<<"OPERATOR: "<<input;//test
    this->expression.push(token(new char(input),1));
}

void parser::getMixed(istream &in, char input)
{
    mixed m;
    in.putback(input);
    in>>m;
    if (!expression.empty() && !expression.back().getType())
        throw INVALID_EXPRESSION;
    qDebug()<<"OPERAND: "<<m.getNum()<<"/"<<m.getDenom();//test
    this->expression.push(token(new mixed(m),0));
}

istream& operator>>(istream &in, parser& p)
{
    char input;
    string op="*/^+-()ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    in>>ws>>input;
    (op.find_first_of(input)!=string::npos ? p.getOp(in,input) : p.getMixed(in,input));
    return in;
}

ostream& operator<<(ostream &out, parser p)
{
    while (!p.expression.empty())
    {
        (p.expression.top().getType() ? out<<*(char*)p.expression.dequeue().getData()<<" "
                                      : out<<*(mixed*)p.expression.dequeue().getData()<<" ");
    }
    return out;
}
