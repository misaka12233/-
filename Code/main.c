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
void printCode(Code code, FILE* output)
{
    if (code == 0) 
        return;
    char name1[50], name2[50], name3[50];
    getName(code->arg1, name1);
    getName(code->arg2, name2);
    getName(code->result, name3);
    switch (code->kind)
    {
        case IR_LABEL:
            fprintf(output, "LABEL %s :\n", name3);
            break;
        case IR_FUNC:
            fprintf(output, "FUNCTION %s :\n", name3);
            break;
        case IR_ASSIGN:
            fprintf(output, "%s := %s\n", name3, name1);
            break;
        case IR_PLUS:
            fprintf(output, "%s := %s + %s\n", name3, name1, name2);
            break;
        case IR_MINUS:
            fprintf(output, "%s := %s - %s\n", name3, name1, name2);
            break;
        case IR_MUL:
            fprintf(output, "%s := %s * %s\n", name3, name1, name2);
            break;
        case IR_DIV:
            fprintf(output, "%s := %s / %s\n", name3, name1, name2);
            break;
        case IR_GOTO:
            fprintf(output, "GOTO %s\n", name3);
            break;
        case IR_IF_G:
            fprintf(output, "IF %s > %s GOTO %s\n", name1, name2, name3);
            break;
        case IR_IF_L:
            fprintf(output, "IF %s < %s GOTO %s\n", name1, name2, name3);
            break;
        case IR_IF_GEQ:
            fprintf(output, "IF %s >= %s GOTO %s\n", name1, name2, name3);
            break;
        case IR_IF_LEQ:
            fprintf(output, "IF %s <= %s GOTO %s\n", name1, name2, name3);
            break;
        case IR_IF_EQ:
            fprintf(output, "IF %s == %s GOTO %s\n", name1, name2, name3);
            break;
        case IR_IF_NEQ:
            fprintf(output, "IF %s != %s GOTO %s\n", name1, name2, name3);
            break;
        case IR_RET:
            fprintf(output, "RETURN %s\n", name3);
            break;
        case IR_DEC:
            fprintf(output, "DEC %s %s\n", name3, name1);
            break;
        case IR_ARG:
            fprintf(output, "ARG %s\n", name3);
            break;
        case IR_CALL:
            fprintf(output, "%s := CALL %s\n", name3, name1);
            break;
        case IR_PARAM:
            fprintf(output, "PARAM %s\n", name3);
            break;
        case IR_READ:
            fprintf(output, "READ %s\n", name3);
            break;
        case IR_WRITE:
            fprintf(output, "WRITE %s\n", name3);
            break;
    }
    printCode(code->nxt, output);
}
int main(int argc, char** argv)
{
    if (argc <= 1) return 1;
    FILE* f = fopen(argv[1], "r");
    FILE* output = fopen("result.ir", "w");
    if (!f)
    {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    //yydebug = 1;
    yyparse();
    if (errorCnt == 0)
    {
        semanticAnalysis();
        if (errorCnt == 0)
        {
            optimizeIR(root->code);
            printCode(root->code, output);
        }
    }
    return 0;
}