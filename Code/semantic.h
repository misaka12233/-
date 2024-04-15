#include <stdlib.h>

typedef struct Type_* Type;
typedef struct FieldList_* FieldList;
typedef struct HashTable_* HashTable;
typedef struct Operand_* Operand;

struct Type_ 
{ 
    enum { BASIC, ARRAY, STRUCTURE, UNKNOWN } kind; 
    int bytes;
    union 
    { 
        // 基本类型 
        // int 0
        // float 1
        int basic; 
        // 数组类型信息包括元素类型与数组大小构成 
        struct { Type elem; int size; } array; 
        // 结构体类型信息是一个链表 
        FieldList structure; 
    } u; 
}; 

struct FieldList_ 
{ 
    char* name; // 域的名字 
    Type type; // 域的类型 
    FieldList nxt; // 下一个域 
}; 

struct HashTable_
{
    enum { VAR, TYP, FUNC } kind; 
    Type type;
    char* name;
    int line;
    int stackId;
    Operand op;
    HashTable nxtTable, nxtStack;
    union
    {
        struct { int size; int def; Type type[32]; } para;
        struct { int type; double val; } init;
        // type == 0 : 无初始化
        // type == 1 : 整数初始化
        // type == 2 : 浮点数初始化
    } u;
};

Type newType();
int getHead(char *name);
void freeStack(int final);
int compareType(Type t1, Type t2);
Type getField(char *name, FieldList now);
int comparePara(HashTable x, HashTable y);
HashTable searchTable(char *name, int kind);
HashTable newFunc(Type type, char *name, int line);
HashTable newSymbol(int kind, Type type, char *name, int line);

void semanticAnalysis();