#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <mixed.h>
#include <string>
#include <sstream>
#include "basenode.h"

class token
{
    public:
        token();
        token(void* d, int ty);
        ~token();
        token(const token &other);
        token& operator=(const token &other);

        void*& setData();
        int& setType();
        void* getData() const;
        int getType() const;

        friend
        ostream& operator<<(ostream &out, token number);

    private:
        void *data;
        int type; //either mixed or operator (0 or 1)
};

#endif // TOKEN_H
