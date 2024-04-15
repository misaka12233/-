#include "syntax.tab.h"
#include "head.h"

extern int errorCnt;
extern int isErrorLine[maxLine];
extern struct node* root;

void getName(Operand op, char* name)
{
    switch (op->kind)
    {
        case PRE_NULL:
            sprintf(name, "%s", op->name);
            break;
        case PRE_AND:
            sprintf(name, "&%s", op->name);
            break;
        case PRE_STAR:
            sprintf(name, "*%s", op->name);
            break;
    }
}
void printCode(Code code)
{
    if (code == 0) 
        return;
    char name1[50], name2[50], name3[50];
    if (code->kind == IR_CALL && code->result->kind == OP_EMPTY)
        code->result = newTempOp();
    getName(code->arg1, name1);
    getName(code->arg2, name2);
    getName(code->result, name3);
    if (code->result->kind != OP_EMPTY)
    {
        switch (code->kind)
        {
        case IR_LABEL:
            printf("LABEL %s :\n", name3);
            break;
        case IR_FUNC:
            printf("FUNCTION %s:\n", name3);
            break;
        case IR_ASSIGN:
            printf("%s := %s\n", name3, name1);
            break;
        case IR_PLUS:
            printf("%s := %s + %s\n", name3, name1, name2);
            break;
        case IR_MINUS:
            printf("%s := %s - %s\n", name3, name1, name2);
            break;
        case IR_MUL:
            printf("%s := %s * %s\n", name3, name1, name2);
            break;
        case IR_DIV:
            printf("%s := %s / %s\n", name3, name1, name2);
            break;
        case IR_GOTO:
            printf("GOTO %s\n", name3);
            break;
        case IR_IF_G:
            printf("IF %s > %s GOTO %s\n", name1, name2, name3);
            break;
        case IR_IF_L:
            printf("IF %s < %s GOTO %s\n", name1, name2, name3);
            break;
        case IR_IF_GEQ:
            printf("IF %s >= %s GOTO %s\n", name1, name2, name3);
            break;
        case IR_IF_LEQ:
            printf("IF %s <= %s GOTO %s\n", name1, name2, name3);
            break;
        case IR_IF_EQ:
            printf("IF %s == %s GOTO %s\n", name1, name2, name3);
            break;
        case IR_IF_NEQ:
            printf("IF %s != %s GOTO %s\n", name1, name2, name3);
            break;
        case IR_RET:
            printf("RETURN %s\n", name3);
            break;
        case IR_DEC:
            printf("DEC %s %s\n", name3, name1);
            break;
        case IR_ARG:
            printf("ARG %s\n", name3);
            break;
        case IR_CALL:
            printf("%s := CALL %s\n", name3, name1);
            break;
        case IR_PARAM:
            printf("PARAM %s\n", name3);
            break;
        case IR_READ:
            break;
        case IR_WRITE:
            break;
        }
    }
    printCode(code->nxt);
}
int main(int argc, char** argv)
{
    if (argc <= 1) return 1;
    FILE* f = fopen(argv[1], "r");
    if (!f)
    {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    //yydebug = 1;
    yyparse();
    if (errorCnt == 0)
        semanticAnalysis();
    printCode(root->code);
    return 0;
}