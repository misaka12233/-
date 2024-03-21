#include <stdio.h>
#include "syntax.tab.h"
#include "head.h"

extern int errorCnt;
extern int isErrorLine[maxLine];
extern struct node* root;

void printSpace(int x) { while (x--) printf(" "); }
void printSyntaxTree(struct node* now, int dep)
{
    if (now->type == SYNTAX_UNIT)
    {
        if (now->childCnt != 0)
        {
            printSpace(dep * 2);
            printf("%s (%d)\n", now->name, now->line);
        }
    }
    else if (now->type == TOKEN_ID)
    {
        printSpace(dep * 2);
        printf("%s: %s\n", now->name, now->data.strVal);
    }
    else if (now->type == TOKEN_TYPE)
    {
        printSpace(dep * 2);
        printf("%s: %s\n", now->name, now->data.strVal);
    }
    else if (now->type == TOKEN_INT)
    {
        printSpace(dep * 2);
        printf("%s: %d\n", now->name, now->data.intVal);
    }
    else if (now->type == TOKEN_FLOAT)
    {
        printSpace(dep * 2);
        printf("%s: %f\n", now->name, now->data.floatVal);
    }
    else if (now->type == TOKEN_OTHER)
    {
        printSpace(dep * 2);
        printf("%s\n", now->name);
    }
    for (int i = 0; i < now->childCnt; i++)
        printSyntaxTree(now->child[i], dep + 1);
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
        printSyntaxTree(root, 0);
    return 0;
}