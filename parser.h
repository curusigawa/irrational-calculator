#ifndef PARSER_H
#define PARSER_H
#include <mixed.h>
#include <token.h>
#include "linkedlistqueue.h"
#include "linkedliststack.h"

enum PARSER_ERR {INVALID_EXPRESSION};

class parser
{
    public:
        parser();
        ~parser();
        parser& operator=(const parser &other);

        void getOp(istream &in, char input);
        void getMixed(istream &in, char input);

        friend
        istream& operator>>(istream &in, parser& p);

        friend
        ostream& operator<<(ostream &out, parser p);

        LinkedListQueue<token> expression;
};

#endif // PARSER_H
