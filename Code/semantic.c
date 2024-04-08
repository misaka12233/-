#include "semantic.h"

extern struct node* root;

#define MAX_TABLE 0x3fff

int top;
int printError;
HashTable stack[MAX_TABLE];
HashTable symbolHead[MAX_TABLE];
struct Type_ intType, floatType, unknownType;

void init()
{
    top = -1;
    memset(stack, 0, sizeof(stack));
    memset(symbolHead, 0, sizeof(symbolHead));
    intType.kind = BASIC;
    intType.u.basic = 0;
    floatType.kind = BASIC;
    floatType.u.basic = 1;
    unknownType.kind = UNKNOWN;
    unknownType.u.basic = 0;
}

int getHead(char *name)
{
    unsigned int val = 0, i;
    for (; *name; name++)
    {
        val = (val << 2) + *name;
        if (i = val & ~MAX_TABLE) val = (val ^ (i >> 12)) & MAX_TABLE;
    }
    return val;
}
void freeStack(int final)
{
    HashTable now = stack[top], nxt;
    while (now != 0)
    {
        symbolHead[getHead(now->name)] = now->nxtTable;
        nxt = now->nxtStack;
        if (final == 1 && now->kind == FUNC && now->u.para.def == 0)
            printf("Error type 18 at Line %d: undefined Function.\n", now->line);
        free(now);
        now = nxt;
    }
    stack[top] = 0;
    top--;
}
Type newType()
{
    Type type = (Type)malloc(sizeof(struct Type_));
    HashTable now = stack[top];
    FieldList lst = 0;
    type->kind = STRUCTURE;
    type->u.structure = 0;
    while (now != 0)
    {
        type->u.structure = (FieldList)malloc(sizeof(struct FieldList_));
        type->u.structure->name = now->name;
        type->u.structure->type = now->type;
        type->u.structure->nxt = lst;
        lst = type->u.structure;
        if (now->u.init.type != 0)
            printf("Error type 15 at Line %d: illegal initial.\n", now->line);
        now = now->nxtStack;
    }
    freeStack(0);
    return type;
}

int compareType(Type t1, Type t2)
{
    if (t1 == 0 || t2 == 0)
        return 1;
    if (t1->kind == t2->kind)
    {
        if (t1->kind == BASIC)
            return t1->u.basic == t2->u.basic;
        else if (t1->kind == ARRAY)
            return t1->u.array.size == t2->u.array.size && compareType(t1->u.array.elem, t2->u.array.elem);
        else if (t1->kind == STRUCTURE)
        {
            int res = 1;
            FieldList now1 = t1->u.structure, now2 = t2->u.structure;
            while (now1 != 0 && now2 != 0)
            {
                res &= compareType(now1->type, now2->type);
                now1 = now1->nxt;
                now2 = now2->nxt;
            }
            return res && now1 == 0 && now2 == 0;
        }
    }
    return 0;
}
int comparePara(HashTable x, HashTable y)
{
    if (x->u.para.size == y->u.para.size)
    {
        int res = 1;
        for (int i = 0; i < x->u.para.size; i++)
            res &= compareType(x->u.para.type[i], y->u.para.type[i]);
        return res;
    }
    return 0;
}
HashTable searchTable(char *name, int kind)
{
    int head = getHead(name);
    HashTable res = 0, now = symbolHead[head];
    while (now != 0)
    {
        if (strcmp(now->name, name) == 0 && now->kind == kind && (res == 0 || res->stackId < now->stackId))
            res = now;
        now = now->nxtTable;
    }
    return res;
}
Type getField(char *name, FieldList now)
{
    while (now != 0)
    {
        if (strcmp(name, now->name) == 0)
            return now->type;
        now = now->nxt;
    }
    return 0;
}

// 非function符号
HashTable newSymbol(int kind, Type type, char *name, int line)
{
    HashTable symbol;
    symbol = searchTable(name, kind);
    if (symbol != 0 && symbol->stackId == top)
        return 0;
    symbol = searchTable(name, 1 - kind);
    if (symbol != 0 && symbol->stackId == top)
        return 0;
    symbol = (HashTable)malloc(sizeof(struct HashTable_));
    symbol->kind = kind;
    symbol->type = type;
    symbol->name = name;
    symbol->line = line;
    symbol->stackId = top;
    symbol->u.init.type = 0;
    int head = getHead(name); symbol->nxtTable = symbolHead[head]; symbolHead[head] = symbol;
    symbol->nxtStack = stack[top]; stack[top] = symbol;
    return symbol;
}

// function符号
HashTable newFunc(Type type, char *name, int line)
{
    HashTable symbol = (HashTable)malloc(sizeof(struct HashTable_));
    HashTable now = stack[top];
    symbol->kind = FUNC;
    symbol->type = type;
    symbol->name = name;
    symbol->line = line;
    symbol->u.para.size = 0;
    symbol->u.para.def = 0;
    while (now != 0)
    {
        symbol->u.para.type[symbol->u.para.size] = now->type;
        symbol->u.para.size++;
        now = now->nxtStack;
    }
    symbol->stackId = top - 1;
    HashTable symbolInTable = searchTable(name, FUNC);
    if (symbolInTable != 0)
    {
        if (comparePara(symbol, symbolInTable))
            return symbolInTable;
        else
            return 0;
    }
    else
    {
        int head = getHead(name); symbol->nxtTable = symbolHead[head]; symbolHead[head] = symbol;
        symbol->nxtStack = stack[top - 1]; stack[top - 1] = symbol;
        return symbol;
    }
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
        case 24:
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
             now->data.ptVal = type;
             break;
        case 51:
            symbol = searchTable(now->child[0]->data.strVal, FUNC);
            if (symbol == 0)
            {
                symbol = searchTable(now->child[0]->data.strVal, VAR);
                if (symbol != 0)
                    printf("Error type 11 at Line %d: varible cannot call as function.\n", now->line);
                else
                    printf("Error type 2 at Line %d: undefined function.\n", now->line);
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
                    printf("Error type 11 at Line %d: varible cannot call as function.\n", now->line);
                else
                    printf("Error type 2 at Line %d: undefined function.\n", now->line);
            }
            else 
            {
                now->data.ptVal = symbol->type;
                if (symbol->u.para.size != 0)
                    printf("Error type 9 at Line %d: error number of arguements for function.\n", now->line);
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
                printf("Error type 4 at Line %d: redefined function.\n", now->line);
            if (symbol != 0)
            {
                symbol->u.para.def = 1;
                if (!compareType(symbol->type, now->child[2]->data.ptVal))
                    printf("Error type 8 at Line %d: error return type.\n", now->line);
            }
            freeStack(0);
            break;
        case 7:
            if (now->child[1]->data.ptVal == 0)
                printf("Error type 19 at Line %d: conflict function define.\n", now->line);
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
                printf("Error type 16 at Line %d: duplicate name.\n", now->line);
            symbol = searchTable(now->child[1]->data.strVal, TYP);
            if (symbol == 0) 
                printf("Error type 17 at Line %d: undefined struct.\n", now->line);
            else
                fa->data.ptVal = now->data.ptVal = symbol->type;
            break;
        case 13:
            fa->data.ptVal = now->data.ptVal = newType();
            if (strlen(now->child[1]->data.strVal) != 0)
            {
                if (newSymbol(TYP, now->data.ptVal, now->child[1]->data.strVal, now->line) == 0)
                    printf("Error type 16 at Line %d: duplicate name.\n", now->line);
            }
            if (printError == 2)
                printf("Error type 15 at Line %d: duplicate definition.\n", now->line);
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
                if (printError == 1) printError = 2;
                else printf("Error type 3 at Line %d: duplicate name.\n", now->line);
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
            now->data.ptVal = now->child[2]->data.ptVal;
            freeStack(0);
            break;
        case 26:
            if (!compareType(now->child[0]->data.ptVal, now->child[1]->data.ptVal))
                now->data.ptVal = now->child[0]->data.ptVal;
            else if (now->child[0]->data.ptVal != 0)
                now->data.ptVal = now->child[0]->data.ptVal;
            else
                now->data.ptVal = now->child[1]->data.ptVal;
            break;
        case 28:
            now->data.ptVal = now->child[0]->data.ptVal;
            break;
        case 29:
            now->data.ptVal = now->child[1]->data.ptVal;
            break;
        case 30:
            now->data.ptVal = now->child[4]->data.ptVal;
            break;
        case 31:
            if (!compareType(now->child[4]->data.ptVal, now->child[6]->data.ptVal))
                now->data.ptVal = now->child[4]->data.ptVal;
            else if (now->child[4]->data.ptVal != 0)
                now->data.ptVal = now->child[4]->data.ptVal;
            else
                now->data.ptVal = now->child[6]->data.ptVal;
            break;
        case 32:
            now->data.ptVal = now->child[4]->data.ptVal;
            break;
        case 39:
            symbol = now->child[0]->data.ptVal;
            if (symbol != 0) symbol->u.init.type = 1;
            break;
        case 40:
            if (!compareType(now->child[0]->data.ptVal, now->child[2]->data.ptVal))
                printf("Error type 5 at Line %d: conflict type in assginment.\n", now->line);
            if (now->child[0]->type == EXP_R_VALUE)
                printf("Error type 6 at Line %d: expression cannot used in right.\n", now->line);
            now->data.ptVal = now->child[0]->data.ptVal;
            now->type = EXP_R_VALUE;
            break;
        case 41:
        case 42:
            if (!compareType(now->child[0]->data.ptVal, &intType) 
            || !compareType(now->child[2]->data.ptVal, &intType))
                printf("Error type 7 at Line %d: illegal operator.\n", now->line);
            now->data.ptVal = &intType;
            now->type = EXP_R_VALUE;
            break;
        case 43:
            if (!compareType(now->child[0]->data.ptVal, now->child[2]->data.ptVal) || 
            (!compareType(now->child[0]->data.ptVal, &intType) && !compareType(now->child[0]->data.ptVal, &floatType)))
                printf("Error type 7 at Line %d: illegal operator.\n", now->line);
            now->data.ptVal = &intType;
            now->type = EXP_R_VALUE;
            break;
        case 44:
        case 45:
        case 46:
        case 47:
            if (!compareType(now->child[0]->data.ptVal, now->child[2]->data.ptVal) || 
            (!compareType(now->child[0]->data.ptVal, &intType) && !compareType(now->child[0]->data.ptVal, &floatType)))
                printf("Error type 7 at Line %d: illegal operator.\n", now->line);
            now->data.ptVal = now->child[0]->data.ptVal;
            now->type = EXP_R_VALUE;
            break;
        case 48:
            now->data.ptVal = now->child[1]->data.ptVal;
            now->type = EXP_R_VALUE;
            break;
        case 49:
            if (!compareType(now->child[1]->data.ptVal, &intType) && !compareType(now->child[1]->data.ptVal, &floatType))
                printf("Error type 7 at Line %d: illegal operator.\n", now->line);
            now->data.ptVal = now->child[1]->data.ptVal;
            now->type = EXP_R_VALUE;
            break;
        case 50:
            if (!compareType(now->child[1]->data.ptVal, &intType))
                printf("Error type 7 at Line %d: illegal operator.\n", now->line);
            now->data.ptVal = now->child[1]->data.ptVal;
            now->type = EXP_R_VALUE;
            break;
        case 51:
            symbol = searchTable(now->child[0]->data.strVal, FUNC);
            if (symbol != 0 && now->child[2]->data.intVal != symbol->u.para.size)
                printf("Error type 9 at Line %d: error number of arguements for function.\n", now->line);
            break;
        case 53:
            type = now->child[0]->data.ptVal;
            if (type == 0 || type->kind != ARRAY)
                printf("Error type 10 at Line %d: illegal array visit.\n", now->line);
            if (!compareType(now->child[2]->data.ptVal, &intType))
                printf("Error type 12 at Line %d: illegal array visit.\n", now->line);
            if (type != 0)
                now->data.ptVal = type->u.array.elem;
            now->type = EXP_LR_VALUE;
            break;
        case 54:
            type = now->child[0]->data.ptVal;
            if (type == 0 || type->kind != STRUCTURE)
                printf("Error type 13 at Line %d: illegal struct visit.\n", now->line);
            else 
            {
                now->data.ptVal = getField(now->child[2]->data.strVal, type->u.structure);
                if (now->data.ptVal == 0)
                    printf("Error type 14 at Line %d: illegal struct visit.\n", now->line);
            }
            now->type = EXP_LR_VALUE;
            break;
        case 55:
            symbol = searchTable(now->child[0]->data.strVal, VAR);
            if (symbol == 0)
                printf("Error type 1 at Line %d: undefined varible.\n", now->line);
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
                printf("Error type 9 at Line %d: error type arguement for function.\n", now->line);
            break;
        case 59:
            symbol = now->data.ptVal;
            now->data.intVal = 1;
            if (symbol != 0 && !compareType(now->child[0]->data.ptVal, symbol->u.para.type[now->data.intVal - 1]))
                printf("Error type 9 at Line %d: error type arguement for function.\n", now->line);
            break;
    }
}

void visitTree(struct node* now, struct node* fa)
{
    actionBeforeChild(now, fa);
    for (int i = 0; i < now->childCnt; i++)
        visitTree(now->child[i], now);
    actionAfterChild(now, fa);
}

void semanticAnalysis()
{
    init();
    visitTree(root, 0);
}