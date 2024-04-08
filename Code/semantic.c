#include "semantic.h"

extern struct node* root;

#define MAX_TABLE 0x3fff

int top;
int printError;
HashTable stack[MAX_TABLE];
HashTable symbolHead[MAX_TABLE];
struct Type_ intType, floatType, unknownType;

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
