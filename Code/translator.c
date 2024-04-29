#include "head.h"
#include <stdarg.h>
#include <assert.h>

struct Operand_ emptyOp, zeroOp, oneOp, fourOp;

void makeSymbolOp(HashTable symbol)
{
    static int varId = 0;
    Operand op = malloc(sizeof(struct Operand_));
    symbol->op = op;
    if (symbol->kind == VAR && symbol->type->kind != BASIC)
        op->kind = PRE_AND;
    else
        op->kind = PRE_NULL;
    if (symbol->kind == FUNC)
        sprintf(op->name, "%s", symbol->name);
    else
        sprintf(op->name, "var%d", varId++);
}

Code codeConnect(int codeCnt, ...)
{
    va_list code;
    va_start(code, codeCnt);
    int i = 1;
    Code st = va_arg(code, Code), now, nxt;
    while (st == 0 && i < codeCnt)
    {
        st = va_arg(code, Code);
        i = i + 1;
    }
    now = st;
    for (; i < codeCnt; i++)
    {
        nxt = va_arg(code, Code);
        while (now->nxt != 0)
            now = now->nxt;
        now->nxt = nxt;
    }
    return st;
}
void freeNextCode(Code code)
{
    Code f = code->nxt;
    code->nxt = f->nxt;
    free(f);
}

Operand newIntOp(int preNeed, int val)
{
    Operand op = malloc(sizeof(struct Operand_));
    op->kind = PRE_NULL;
    if (preNeed)
        sprintf(op->name, "#%d", val);
    else
        sprintf(op->name, "%d", val);
    return op;
}
Operand newFloatOp(double val)
{
    Operand op = malloc(sizeof(struct Operand_));
    op->kind = PRE_NULL;
    sprintf(op->name, "#%lf", val);
    return op;
}
Operand newLabelOp()
{
    static int labelId = 0;
    labelId++;
    Operand op = malloc(sizeof(struct Operand_));
    op->kind = PRE_NULL;
    sprintf(op->name, "Label%d", labelId);
    return op;
}
Operand newTempOp()
{
    static int tempId = 0;
    tempId++;
    Operand op = malloc(sizeof(struct Operand_));
    op->kind = PRE_NULL;
    sprintf(op->name, "temp%d", tempId);
    return op;
}
Operand newCopyOp(Operand op1, int kind)
{
    Operand op2 = malloc(sizeof(struct Operand_));
    op2->kind = kind;
    strcpy(op2->name, op1->name);
    return op2;
}
Code newCode(int kind, Operand arg1, Operand arg2, Operand result)
{
    Code code = malloc(sizeof(struct Code_));
    code->kind = kind;
    code->arg1 = arg1;
    code->arg2 = arg2;
    code->result = result;
    code->nxt = 0;
    return code;
}
Code newFuncCode(HashTable func)
{
    return newCode(IR_FUNC, &emptyOp, &emptyOp, func->op);
}
Code newVarDecCode(HashTable var)
{
    if (var->type->kind != BASIC)
    {
        Operand t = newCopyOp(var->op, PRE_NULL);
        return newCode(IR_DEC, newIntOp(0, var->type->bytes), &emptyOp, t);
    }
    else
        return 0;
}
Code newParaCode(HashTable var)
{
    var->op->kind = PRE_NULL;
    return newCode(IR_PARAM, &emptyOp, &emptyOp, var->op);
}

void fillEmpty(Code code, Operand op)
{
    while (code != 0)
    {
        if (code->result->kind == OP_EMPTY)
            code->result = op;
        code = code->nxt;
    }
}
void getValCode(int kind, Code exp, int id)
{
    Operand t1, t2;
    if (kind == BASIC && (id == 53 || id == 54))
    {
        t1 = newTempOp();
        t2 = newCopyOp(t1, PRE_STAR);
        fillEmpty(exp, t1);
        codeConnect(2, exp, newCode(IR_ASSIGN, t2, &emptyOp, &emptyOp));
    }
}
Code newExpAssignCode(Type type, Code exp1, int id1, Code exp2, int id2)
{
    Operand t1, t2, t3, t4;
    if (type->kind == BASIC)
    {
        if (id1 == 55)
        {
            t1 = newTempOp();
            getValCode(type->kind, exp2, id2);
            fillEmpty(exp2, t1);
            exp2 = codeConnect(3, exp2, 
                                newCode(IR_ASSIGN, t1, &emptyOp, exp1->arg1), 
                                newCode(IR_ASSIGN, exp1->arg1, &emptyOp, &emptyOp));
            free(exp1);
            return exp2;
        }
        else
        {
            t1 = newTempOp();
            t2 = newTempOp();
            getValCode(type->kind, exp2, id2);
            fillEmpty(exp1, t1);
            fillEmpty(exp2, t2);
            t3 = newCopyOp(t1, PRE_STAR);
            return codeConnect(4, exp1, exp2, 
                                newCode(IR_ASSIGN, t2, &emptyOp, t3), 
                                newCode(IR_ASSIGN, t3, &emptyOp, &emptyOp));
        }
    }
    else
    {
        t1 = newTempOp();
        t2 = newTempOp();
        fillEmpty(exp1, t1);
        fillEmpty(exp2, t2);
        t3 = newCopyOp(t1, PRE_STAR);
        t4 = newCopyOp(t2, PRE_STAR);
        Code code = codeConnect(3, exp1, exp2, newCode(IR_ASSIGN, t3, &emptyOp, t4));
        for (int i = 4; i < type->bytes; i += 4)
            code = codeConnect(3, code, 
                                newCode(IR_PLUS, t1, &fourOp, t1), 
                                newCode(IR_PLUS, t2, &fourOp, t2), 
                                newCode(IR_ASSIGN, t3, &emptyOp, t4));
        return codeConnect(2, code, newCode(IR_MINUS, t1, newIntOp(1, type->bytes - 4), &emptyOp));
    }
}
Code newAndExpCode(Code exp1, int id1, Code exp2, int id2)
{
    Operand t1 = newTempOp(), t2 = newTempOp();
    Operand label = newLabelOp();
    getValCode(BASIC, exp1, id1);
    getValCode(BASIC, exp2, id2);
    fillEmpty(exp1, t1);
    fillEmpty(exp2, t2);
    return codeConnect(7, newCode(IR_ASSIGN, &zeroOp, &emptyOp, &emptyOp),
                        exp1,
                        newCode(IR_IF_EQ, t1, &zeroOp, label),
                        exp2,
                        newCode(IR_IF_EQ, t2, &zeroOp, label),
                        newCode(IR_ASSIGN, &oneOp, &emptyOp, &emptyOp),
                        newCode(IR_LABEL, &emptyOp, &emptyOp, label));
}
Code newOrExpCode(Code exp1, int id1, Code exp2, int id2)
{
    Operand t1 = newTempOp(), t2 = newTempOp();
    Operand label = newLabelOp();
    getValCode(BASIC, exp1, id1);
    getValCode(BASIC, exp2, id2);
    fillEmpty(exp1, t1);
    fillEmpty(exp2, t2);
    return codeConnect(7, newCode(IR_ASSIGN, &oneOp, &emptyOp, &emptyOp),
                        exp1,
                        newCode(IR_IF_NEQ, t1, &zeroOp, label),
                        exp2,
                        newCode(IR_IF_NEQ, t2, &zeroOp, label),
                        newCode(IR_ASSIGN, &zeroOp, &emptyOp, &emptyOp),
                        newCode(IR_LABEL, &emptyOp, &emptyOp, label));
}
Code newRelopExpCode(char* relop, Code exp1, int id1, Code exp2, int id2)
{
    Operand t1 = newTempOp(), t2 = newTempOp();
    Operand label = newLabelOp();
    getValCode(BASIC, exp1, id1);
    getValCode(BASIC, exp2, id2);
    fillEmpty(exp1, t1);
    fillEmpty(exp2, t2);
    int kind = IR_IF_EQ;
    if (strcmp(relop, ">") == 0) kind = IR_IF_G;
    else if (strcmp(relop, ">=") == 0) kind = IR_IF_GEQ;
    else if (strcmp(relop, "<") == 0) kind = IR_IF_L;
    else if (strcmp(relop, "<=") == 0) kind = IR_IF_LEQ;
    else if (strcmp(relop, "==") == 0) kind = IR_IF_EQ;
    else if (strcmp(relop, "!=") == 0) kind = IR_IF_NEQ;
    return codeConnect(6, newCode(IR_ASSIGN, &oneOp, &emptyOp, &emptyOp),
                        exp1,
                        exp2,
                        newCode(kind, t1, t2, label),
                        newCode(IR_ASSIGN, &zeroOp, &emptyOp, &emptyOp),
                        newCode(IR_LABEL, &emptyOp, &emptyOp, label));
}
Code newExpCode(int kind, Code exp1, int id1, Code exp2, int id2)
{
    Operand t1 = newTempOp(), t2 = newTempOp();
    getValCode(BASIC, exp1, id1);
    getValCode(BASIC, exp2, id2);
    fillEmpty(exp1, t1);
    fillEmpty(exp2, t2);
    return codeConnect(3, exp1, exp2, newCode(kind, t1, t2, &emptyOp));
}
Code newMinusExpCode(Code exp, int id)
{
    Operand t = newTempOp();
    getValCode(BASIC, exp, id);
    fillEmpty(exp, t);
    return codeConnect(2, exp, newCode(IR_MINUS, &zeroOp, t, &emptyOp));
}
Code newNotExpCode(Code exp, int id)
{
    Operand t = newTempOp();
    Operand label = newLabelOp();
    getValCode(BASIC, exp, id);
    fillEmpty(exp, t);
    return codeConnect(5, newCode(IR_ASSIGN, &oneOp, &emptyOp, &emptyOp),
                        exp,
                        newCode(IR_IF_EQ, t, &zeroOp, label),
                        newCode(IR_ASSIGN, &zeroOp, &emptyOp, &emptyOp),
                        newCode(IR_LABEL, &emptyOp, &emptyOp, label));
}
Code newCallCode(HashTable func, Code argCode)
{
    if (strcmp(func->name, "write") == 0)
    {
        Code lstCode = argCode;
        while (lstCode->nxt != 0)
            lstCode = lstCode->nxt;
        lstCode->kind = IR_WRITE;
        return codeConnect(2, argCode, newCode(IR_ASSIGN, &zeroOp, &emptyOp, &emptyOp));
    }
    else if (strcmp(func->name, "read") == 0)
        return newCode(IR_READ, &emptyOp, &emptyOp, &emptyOp);
    else
        return codeConnect(2, argCode, newCode(IR_CALL, func->op, &emptyOp, &emptyOp));
}
Code newArrayExpCode(Type type, Code exp1, Code exp2, int id2)
{
    Operand t1 = newTempOp(), t2 = newTempOp();
    getValCode(BASIC, exp2, id2);
    fillEmpty(exp1, t1);
    fillEmpty(exp2, t2);
    return codeConnect(4, exp1, exp2,
                        newCode(IR_MUL, t2, newIntOp(1, type->u.array.elem->bytes), t2),
                        newCode(IR_PLUS, t1, t2, &emptyOp));
}
Code newStructExpCode(Type type, Code exp, char* field)
{
    FieldList now = type->u.structure;
    int bytes = 0;
    while (now != 0)
    {
        if (strcmp(field, now->name) == 0)
            break;
        bytes += now->type->bytes;
        now = now->nxt;
    }
    Operand t = newTempOp();
    fillEmpty(exp, t);
    return codeConnect(2, exp, newCode(IR_PLUS, t, newIntOp(1, bytes), &emptyOp));
}
Code newVarExpCode(HashTable var)
{
    return newCode(IR_ASSIGN, var->op, &emptyOp, &emptyOp);
}
Code newImmIntCode(int val)
{
    return newCode(IR_ASSIGN, newIntOp(1, val), &emptyOp, &emptyOp);
}
Code newImmFloatCode(double val)
{
    return newCode(IR_ASSIGN, newFloatOp(val), &emptyOp, &emptyOp);
}
Code newArgCode(Type type, Code exp, int id, Code code)
{
    Operand t = newTempOp();
    getValCode(type->kind, exp, id);
    fillEmpty(exp, t);
    return codeConnect(3, exp, code, newCode(IR_ARG, &emptyOp, &emptyOp, t));
}

Code newRetCode(Code code)
{
    Operand t = newTempOp();
    fillEmpty(code, t);
    return codeConnect(2, code, newCode(IR_RET, &emptyOp, &emptyOp, t));
}
Code newIfCode(Code cond, Code stmt)
{
    Operand t = newTempOp();
    Operand label = newLabelOp();
    fillEmpty(cond, t);
    return codeConnect(4, cond, 
                        newCode(IR_IF_EQ, t, &zeroOp, label), 
                        stmt, 
                        newCode(IR_LABEL, &emptyOp, &emptyOp, label));
}
Code newIfElseCode(Code cond, Code stmt1, Code stmt2)
{
    Operand t = newTempOp();
    Operand label1 = newLabelOp(), label2 = newLabelOp();
    fillEmpty(cond, t);
    return codeConnect(7, cond, 
                        newCode(IR_IF_EQ, t, &zeroOp, label1), 
                        stmt1, 
                        newCode(IR_GOTO, &emptyOp, &emptyOp, label2),
                        newCode(IR_LABEL, &emptyOp, &emptyOp, label1),
                        stmt2,
                        newCode(IR_LABEL, &emptyOp, &emptyOp, label2));
}
Code newWhileCode(Code cond, Code stmt)
{
    Operand t = newTempOp();
    Operand label1 = newLabelOp(), label2 = newLabelOp();
    fillEmpty(cond, t);
    return codeConnect(6, 
                        newCode(IR_LABEL, &emptyOp, &emptyOp, label1),
                        cond, 
                        newCode(IR_IF_EQ, t, &zeroOp, label2), 
                        stmt, 
                        newCode(IR_GOTO, &emptyOp, &emptyOp, label1),
                        newCode(IR_LABEL, &emptyOp, &emptyOp, label2));
}
Code newVarInitCode(HashTable var, Code exp, int id)
{
    return codeConnect(2, newVarDecCode(var), newExpAssignCode(var->type, newVarExpCode(var), 55, exp, id));
}

void translateIR(struct node* now)
{
    switch (now->ruleId)
    {
        case 1:
        case 22:
        case 27:
        case 28:
        case 36:
            now->code = now->child[0]->code;
            break;
        case 3:
        case 26:
        case 34:
            now->code = codeConnect(2, now->child[0]->code, now->child[1]->code);
            break;
        //case 4:
        case 35:
        case 48:
            now->code = now->child[1]->code;
            break;
        case 6:
            now->code = codeConnect(3, newFuncCode(now->child[1]->data.ptVal), now->child[1]->code, now->child[2]->code);
            break;
        case 7:
            if (now->child[1]->code != 0)
            {
                while (now->child[1]->code->nxt != 0)
                    freeNextCode(now->child[1]->code);
                free(now->child[1]->code);
                now->child[1]->code = 0;
            }
            break;
        //case 8:
        case 38:
            now->code = newVarDecCode(now->child[0]->data.ptVal);
            break;
        //case 9:
        //    now->code = codeConnect(2, newVarDecCode(now->child[0]->data.ptVal), now->child[2]->code);
        //    break;
        case 19:
            now->code = now->child[2]->code;
            break;
        case 21:
            now->code = codeConnect(2, now->child[0]->code, now->child[2]->code);
            break;
        case 23:
            now->code = newParaCode(now->child[1]->data.ptVal);
            break;
        case 24:
            now->code = codeConnect(2, now->child[1]->code, now->child[2]->code);
            break;
        case 29:
            now->code = newRetCode(now->child[1]->code);
            break;
        case 30:
            now->code = newIfCode(now->child[2]->code, now->child[4]->code);
            break;
        case 31:
            now->code = newIfElseCode(now->child[2]->code, now->child[4]->code, now->child[6]->code);
            break;
        case 32:
            now->code = newWhileCode(now->child[2]->code, now->child[4]->code);
            break;
        case 37:
            now->code = codeConnect(2, now->child[0]->code, now->child[2]->code);
            break;
        case 39:
            now->code = newVarInitCode(now->child[0]->data.ptVal, now->child[2]->code, now->child[2]->ruleId);
            break;
        case 40:
            now->code = newExpAssignCode(now->child[0]->data.ptVal, now->child[0]->code, now->child[0]->ruleId, now->child[2]->code, now->child[2]->ruleId);
            break;
        case 41:
            now->code = newAndExpCode(now->child[0]->code, now->child[0]->ruleId, now->child[2]->code, now->child[2]->ruleId);
            break;
        case 42:
            now->code = newOrExpCode(now->child[0]->code, now->child[0]->ruleId, now->child[2]->code, now->child[2]->ruleId);
            break;
        case 43:
            now->code = newRelopExpCode(now->child[1]->data.strVal, now->child[0]->code, now->child[0]->ruleId, now->child[2]->code, now->child[2]->ruleId);
            break;
        case 44:
            now->code = newExpCode(IR_PLUS, now->child[0]->code, now->child[0]->ruleId, now->child[2]->code, now->child[2]->ruleId);
            break;
        case 45:
            now->code = newExpCode(IR_MINUS, now->child[0]->code, now->child[0]->ruleId, now->child[2]->code, now->child[2]->ruleId);
            break;
        case 46:
            now->code = newExpCode(IR_MUL, now->child[0]->code, now->child[0]->ruleId, now->child[2]->code, now->child[2]->ruleId);
            break;
        case 47:
            now->code = newExpCode(IR_DIV, now->child[0]->code, now->child[0]->ruleId, now->child[2]->code, now->child[2]->ruleId);
            break;
        case 49:
            now->code = newMinusExpCode(now->child[1]->code, now->child[1]->ruleId);
            break;
        case 50:
            now->code = newNotExpCode(now->child[1]->code, now->child[1]->ruleId);
            break;
        case 51:
            now->code = newCallCode(searchTable(now->child[0]->data.strVal, FUNC), now->child[2]->code);
            break;
        case 52:
            now->code = newCallCode(searchTable(now->child[0]->data.strVal, FUNC), 0);
            break;
        case 53:
            now->code = newArrayExpCode(now->child[0]->data.ptVal, now->child[0]->code, now->child[2]->code, now->child[2]->ruleId);
            break;
        case 54:
            now->code = newStructExpCode(now->child[0]->data.ptVal, now->child[0]->code, now->child[2]->data.strVal);
            break;
        case 55:
            now->code = newVarExpCode(searchTable(now->child[0]->data.strVal, VAR));
            break;
        case 56:
            now->code = newImmIntCode(now->child[0]->data.intVal);
            break;
        case 57:
            now->code = newImmFloatCode(now->child[0]->data.floatVal);
            break;
        case 58:
            now->code = newArgCode(now->child[0]->data.ptVal, now->child[0]->code, now->child[0]->ruleId, now->child[2]->code);
            break;
        case 59:
            now->code = newArgCode(now->child[0]->data.ptVal, now->child[0]->code, now->child[0]->ruleId, 0);
            break;
    }
}