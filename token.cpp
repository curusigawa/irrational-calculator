#include "token.h"

token::token()
{
    data = NULL;
    type = -1;
}

token::token(void* d, int ty)
{
    data = d;
    type = ty;
}

token::~token()
{
    data = NULL;
    type = -1;
}

token::token(const token &other)
{
    if (this!=&other)
        *this=other;
}

token& token::operator=(const token &other)
{
    data=other.data;
    type=other.type;
    return *this;
}

void* token::getData() const
{
    return data;
}

int token::getType() const
{
    return type;
}

void*& token::setData()
{
    return data;
}

int& token::setType()
{
    return type;
}

ostream& operator<<(ostream &out, token number)
{
    if (number.type)
        out<<*(char*)(number.data);
    else
        out<<*(mixed*)(number.data);
    return out;
}
