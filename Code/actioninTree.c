#include "head.h"
#define MAX_TABLE 0x3fff

extern struct node* root;
extern int errorCnt;
extern int top;
extern int printError;
extern HashTable stack[MAX_TABLE];
extern HashTable symbolHead[MAX_TABLE];
extern struct Type_ intType, floatType;
extern struct Operand_ emptyOp, zeroOp, oneOp, fourOp;

void init()
{
    top = 0;
    memset(stack, 0, sizeof(stack));
    memset(symbolHead, 0, sizeof(symbolHead));

    intType.kind = BASIC;
    intType.u.basic = 0;
    intType.bytes = 4;
    floatType.kind = BASIC;
    floatType.u.basic = 1;
    floatType.bytes = 4;

    emptyOp.kind = OP_EMPTY;
    zeroOp.kind = PRE_NULL;
    strcpy(zeroOp.name, "#0");
    oneOp.kind = PRE_NULL;
    strcpy(oneOp.name, "#1");
    fourOp.kind = PRE_NULL;
    strcpy(fourOp.name, "#4");

    HashTable symbol = (HashTable)malloc(sizeof(struct HashTable_));
    symbol->kind = FUNC;
    symbol->type = &intType;
    symbol->name = "read";
    symbol->line = 0;
    symbol->u.para.size = 0;
    symbol->u.para.def = 1;
    symbol->stackId = top;
    int head = getHead("read"); symbol->nxtTable = symbolHead[head]; symbolHead[head] = symbol;
    symbol->nxtStack = stack[top]; stack[top] = symbol;

    symbol = (HashTable)malloc(sizeof(struct HashTable_));
    symbol->kind = FUNC;
    symbol->type = &intType;
    symbol->name = "write";
    symbol->line = 0;
    symbol->u.para.size = 1;
    symbol->u.para.def = 1;
    symbol->u.para.type[0] = &intType;
    symbol->stackId = top;
    head = getHead("write"); symbol->nxtTable = symbolHead[head]; symbolHead[head] = symbol;
    symbol->nxtStack = stack[top]; stack[top] = symbol;
}

void actionBeforeChild(struct node* now, struct node* fa)
{
    HashTable symbol;
    Type type;
    switch (now->ruleId)
    {
        case 1:
        case 19:
        case 20:
            top++;
            break;
        case 8:
        case 9:
        case 36:
        case 37:
        case 38:
        case 39:
            now->data.ptVal = fa->data.ptVal;
            break;
        case 13:
            top++;
            printError = 1;
            break;
        case 18:
             type = (Type)malloc(sizeof(struct Type_));
             type->kind = ARRAY;
             type->u.array.elem = fa->data.ptVal;
             type->u.array.size = now->child[2]->data.intVal;
             type->bytes = type->u.array.elem->bytes * type->u.array.size;
             now->data.ptVal = type;
             break;
        case 24:
            top++;
            now->data.ptVal = fa->data.ptVal;
            break;
        case 26:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
            now->data.ptVal = fa->data.ptVal;
            break;
        case 51:
            symbol = searchTable(now->child[0]->data.strVal, FUNC);
            if (symbol == 0)
            {
                symbol = searchTable(now->child[0]->data.strVal, VAR);
                if (symbol != 0)
                    printf("Error type 11 at Line %d: varible cannot call as function.\n", now->line), errorCnt++;
                else
                    printf("Error type 2 at Line %d: undefined function.\n", now->line), errorCnt++;
            }
            else
            {
                now->data.ptVal = symbol->type;
                now->child[2]->data.ptVal = symbol;
            }
            now->type = EXP_R_VALUE;
            break;
        case 52:
            symbol = searchTable(now->child[0]->data.strVal, FUNC);
            if (symbol == 0)
            {
                symbol = searchTable(now->child[0]->data.strVal, VAR);
                if (symbol != 0)
                    printf("Error type 11 at Line %d: varible cannot call as function.\n", now->line), errorCnt++;
                else
                    printf("Error type 2 at Line %d: undefined function.\n", now->line), errorCnt++;
            }
            else 
            {
                now->data.ptVal = symbol->type;
                if (symbol->u.para.size != 0)
                    printf("Error type 9 at Line %d: error number of arguements for function.\n", now->line), errorCnt++;
            }
            now->type = EXP_R_VALUE;
            break;
        case 58:
            now->child[2]->data.ptVal = now->data.ptVal;
            break;
    }
}
void actionAfterChild(struct node* now, struct node* fa)
{
    HashTable symbol;
    Type type;
    switch (now->ruleId)
    {
        case 1:
            freeStack(1);
            break;
        case 6:
            symbol = now->child[1]->data.ptVal;
            if (symbol == 0 || symbol->u.para.def == 1)
                printf("Error type 4 at Line %d: redefined function.\n", now->line), errorCnt++;
            if (symbol != 0)
            {
                symbol->u.para.def = 1;
                if (!compareType(symbol->type, now->child[2]->data.ptVal))
                    printf("Error type 8 at Line %d: error return type.\n", now->line), errorCnt++;
            }
            freeStack(0);
            break;
        case 7:
            if (now->child[1]->data.ptVal == 0)
                printf("Error type 19 at Line %d: conflict function define.\n", now->line), errorCnt++;
            freeStack(0);
            break;
        case 10:
            if (now->child[0]->data.strVal[0] == 'i')
                now->data.ptVal = &intType;
            else
                now->data.ptVal = &floatType;
            fa->data.ptVal = now->data.ptVal;
            break;
        case 11:
            fa->data.ptVal = now->data.ptVal;
            break;
        case 12:
            symbol = searchTable(now->child[1]->data.strVal, VAR);
            if (symbol != 0 && symbol->stackId == top) 
                printf("Error type 16 at Line %d: duplicate name.\n", now->line), errorCnt++;
            symbol = searchTable(now->child[1]->data.strVal, TYP);
            if (symbol == 0) 
                printf("Error type 17 at Line %d: undefined struct.\n", now->line), errorCnt++;
            else
                fa->data.ptVal = now->data.ptVal = symbol->type;
            break;
        case 13:
            fa->data.ptVal = now->data.ptVal = newType();
            if (strlen(now->child[1]->data.strVal) != 0)
            {
                if (newSymbol(TYP, now->data.ptVal, now->child[1]->data.strVal, now->line) == 0)
                    printf("Error type 16 at Line %d: duplicate name.\n", now->line), errorCnt++;
            }
            printError = 0;
            break;
        case 14:
            memset(now->data.strVal, 0, sizeof(now->data.strVal));
            break;
        case 15:
        case 16:
            strcpy(now->data.strVal, now->child[0]->data.strVal);
            break;
        case 17:
            now->data.ptVal = newSymbol(VAR, fa->data.ptVal, now->child[0]->data.strVal, now->line);
            if (now->data.ptVal == 0)
            {
                if (printError == 1) 
                    printf("Error type 15 at Line %d: redefinied.\n", now->line), errorCnt++;
                else 
                    printf("Error type 3 at Line %d: redefinied.\n", now->line), errorCnt++;
            }
            break;
        case 18:
            now->data.ptVal = now->child[0]->data.ptVal;
            break;
        case 19:
        case 20:
            now->data.ptVal = newFunc(fa->data.ptVal, now->child[0]->data.strVal, now->line);
            break;
        case 24:
            freeStack(0);
            break;
        case 29:
            if (!compareType(now->data.ptVal, now->child[1]->data.ptVal))
                printf("Error type 8 at Line %d: Type mismatched for return.\n", now->line), errorCnt++;
            break;
        case 39:
            symbol = now->child[0]->data.ptVal;
            if (symbol != 0) symbol->u.init.type = 1;
            break;
        case 40:
            if (!compareType(now->child[0]->data.ptVal, now->child[2]->data.ptVal))
                printf("Error type 5 at Line %d: conflict type in assginment.\n", now->line), errorCnt++;
            if (now->child[0]->type == EXP_R_VALUE)
                printf("Error type 6 at Line %d: expression cannot used in right.\n", now->line), errorCnt++;
            now->data.ptVal = now->child[0]->data.ptVal;
            now->type = EXP_R_VALUE;
            break;
        case 41:
        case 42:
            if (!compareType(now->child[0]->data.ptVal, &intType) 
            || !compareType(now->child[2]->data.ptVal, &intType))
                printf("Error type 7 at Line %d: illegal operator.\n", now->line), errorCnt++;
            now->data.ptVal = &intType;
            now->type = EXP_R_VALUE;
            break;
        case 43:
            if (!compareType(now->child[0]->data.ptVal, now->child[2]->data.ptVal) || 
            (!compareType(now->child[0]->data.ptVal, &intType) && !compareType(now->child[0]->data.ptVal, &floatType)))
                printf("Error type 7 at Line %d: illegal operator.\n", now->line), errorCnt++;
            now->data.ptVal = &intType;
            now->type = EXP_R_VALUE;
            break;
        case 44:
        case 45:
        case 46:
        case 47:
            if (!compareType(now->child[0]->data.ptVal, now->child[2]->data.ptVal) || 
            (!compareType(now->child[0]->data.ptVal, &intType) && !compareType(now->child[0]->data.ptVal, &floatType)))
                printf("Error type 7 at Line %d: illegal operator.\n", now->line), errorCnt++;
            now->data.ptVal = now->child[0]->data.ptVal;
            now->type = EXP_R_VALUE;
            break;
        case 48:
            now->data.ptVal = now->child[1]->data.ptVal;
            now->type = EXP_R_VALUE;
            break;
        case 49:
            if (!compareType(now->child[1]->data.ptVal, &intType) && !compareType(now->child[1]->data.ptVal, &floatType))
                printf("Error type 7 at Line %d: illegal operator.\n", now->line), errorCnt++;
            now->data.ptVal = now->child[1]->data.ptVal;
            now->type = EXP_R_VALUE;
            break;
        case 50:
            if (!compareType(now->child[1]->data.ptVal, &intType))
                printf("Error type 7 at Line %d: illegal operator.\n", now->line), errorCnt++;
            now->data.ptVal = now->child[1]->data.ptVal;
            now->type = EXP_R_VALUE;
            break;
        case 51:
            symbol = searchTable(now->child[0]->data.strVal, FUNC);
            if (symbol != 0 && now->child[2]->data.intVal != symbol->u.para.size)
                printf("Error type 9 at Line %d: error number of arguements for function.\n", now->line), errorCnt++;
            break;
        case 53:
            type = now->child[0]->data.ptVal;
            if (type == 0 || type->kind != ARRAY)
                printf("Error type 10 at Line %d: illegal array visit.\n", now->line), errorCnt++;
            if (!compareType(now->child[2]->data.ptVal, &intType))
                printf("Error type 12 at Line %d: illegal array visit.\n", now->line), errorCnt++;
            if (type != 0)
                now->data.ptVal = type->u.array.elem;
            now->type = EXP_LR_VALUE;
            break;
        case 54:
            type = now->child[0]->data.ptVal;
            if (type == 0 || type->kind != STRUCTURE)
                printf("Error type 13 at Line %d: illegal struct visit.\n", now->line), errorCnt++;
            else 
            {
                now->data.ptVal = getField(now->child[2]->data.strVal, type->u.structure);
                if (now->data.ptVal == 0)
                    printf("Error type 14 at Line %d: illegal struct visit.\n", now->line), errorCnt++;
            }
            now->type = EXP_LR_VALUE;
            break;
        case 55:
            symbol = searchTable(now->child[0]->data.strVal, VAR);
            if (symbol == 0)
                printf("Error type 1 at Line %d: undefined varible.\n", now->line), errorCnt++;
            else
            {
                now->data.ptVal = symbol->type;
                now->type = EXP_LR_VALUE;
            }
            break;
        case 56:
            now->data.ptVal = &intType;
            now->type = EXP_R_VALUE;
            break;
        case 57:
            now->data.ptVal = &floatType;
            now->type = EXP_R_VALUE;
            break; 
        case 58:
            symbol = now->data.ptVal;
            now->data.intVal = now->child[2]->data.intVal + 1;
            if (!compareType(now->child[0]->data.ptVal, symbol->u.para.type[now->data.intVal - 1]))
                printf("Error type 9 at Line %d: error type arguement for function.\n", now->line), errorCnt++;
            break;
        case 59:
            symbol = now->data.ptVal;
            now->data.intVal = 1;
            if (symbol != 0 && !compareType(now->child[0]->data.ptVal, symbol->u.para.type[now->data.intVal - 1]))
                printf("Error type 9 at Line %d: error type arguement for function.\n", now->line), errorCnt++;
            break;
    }
}

void checkError(struct node* now, struct node* fa)
{
    actionBeforeChild(now, fa);
    for (int i = 0; i < now->childCnt; i++)
        checkError(now->child[i], now);
    actionAfterChild(now, fa);
}
void visitTree(struct node* now, struct node* fa)
{
    actionBeforeChild(now, fa);
    for (int i = 0; i < now->childCnt; i++)
        visitTree(now->child[i], now);
    translateIR(now);
    actionAfterChild(now, fa);
}
void semanticAnalysis()
{
    init();
    checkError(root, 0);
    if (errorCnt == 0)
        visitTree(root, 0);
}