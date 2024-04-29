#include "semantic.h"

typedef struct Code_* Code;
struct node;

struct Operand_{
    enum{
        OP_EMPTY,
        PRE_NULL,
        PRE_AND,
        PRE_STAR
    }kind;
    char name[50];
};

struct Code_{
    enum{
        IR_LABEL,
        IR_FUNC,
        IR_ASSIGN,
        IR_PLUS,
        IR_MINUS,
        IR_MUL,
        IR_DIV,
        IR_GOTO,
        IR_IF_G,
        IR_IF_L,
        IR_IF_GEQ,
        IR_IF_LEQ,
        IR_IF_EQ,
        IR_IF_NEQ,
        IR_RET,
        IR_DEC,
        IR_ARG,
        IR_CALL,
        IR_PARAM,
        IR_READ,
        IR_WRITE
    }kind;
    Operand arg1, arg2, result;
    Code nxt;
};

void translateIR(struct node* now);
void optimizeIR(Code code);
void makeSymbolOp(HashTable symbol);
Operand newTempOp();