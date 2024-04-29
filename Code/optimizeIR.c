#include "head.h"

int isSimpleTemp(Operand op)
{
    if (op->kind != PRE_NULL)
        return 0;
    if (op->name[0] != 't' || op->name[1] != 'e' || op->name[2] != 'm' || op->name[3] != 'p')
        return 0;
    return 1;
}
int compareOp(Operand op1, Operand op2)
{
    return op1->kind == op2->kind && strcmp(op1->name, op2->name) == 0;
}
void deleteEmpty(Code code)
{
    while (code != 0 && code->nxt != 0)
    {
        while (code->nxt != 0 && code->nxt->result->kind == OP_EMPTY)
        {
            if (code->nxt->kind == IR_CALL || code->nxt->kind == IR_READ)
            {
                code->nxt->result = newTempOp();
                break;
            }
            else
                code->nxt = code->nxt->nxt;
        }
        code = code->nxt;
    }
}
void deleteUselessCode(Code code)
{
    while (code->nxt != 0 && code->nxt->nxt != 0)
    {
        if (code->nxt->kind == IR_ASSIGN && isSimpleTemp(code->nxt->result))
        {
            if (compareOp(code->nxt->result, code->nxt->nxt->arg1))
            {
                code->nxt->nxt->arg1 = code->nxt->arg1;
                code->nxt = code->nxt->nxt;
            }
            else if (compareOp(code->nxt->result, code->nxt->nxt->arg2))
            {
                code->nxt->nxt->arg2 = code->nxt->arg1;
                code->nxt = code->nxt->nxt;
            }
            else if (compareOp(code->nxt->result, code->nxt->nxt->result) && 
            (code->nxt->nxt->kind == IR_RET || code->nxt->nxt->kind == IR_ARG || code->nxt->nxt->kind == IR_WRITE))
            {
                code->nxt->nxt->result = code->nxt->arg1;
                code->nxt = code->nxt->nxt;
            }
        }
        else if ((code->kind == IR_READ || code->kind == IR_PLUS 
                || code->kind == IR_MINUS || code->kind == IR_MUL 
                || code->kind == IR_DIV || code->kind == IR_CALL) 
                && isSimpleTemp(code->result))
        {
            if (code->nxt->kind == IR_ASSIGN && compareOp(code->result, code->nxt->arg1) && code->nxt->result->kind != PRE_STAR)
            {
                code->result = code->nxt->result;
                code->nxt = code->nxt->nxt;
            }
        }
        code = code->nxt;
    }
}
#define DeleteTimes 8
void optimizeIR(Code code)
{
    deleteEmpty(code);
    for (int i = 0; i < DeleteTimes; i++)
        deleteUselessCode(code);
}