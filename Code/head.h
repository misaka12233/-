#include <stdio.h>
#include <string.h>

typedef enum unitType
{
    TOKEN_ID = 0,
    TOKEN_TYPE = 1,
    TOKEN_INT = 2,
    TOKEN_FLOAT = 3,
    TOKEN_OTHER = 4,
    SYNTAX_UNIT = 5,
    EXP_LR_VALUE = 6,
    EXP_R_VALUE = 7,
    ERROR_UNIT = 255
} unitType;
typedef union Data
{
    int intVal;
    double floatVal;
    char strVal[32];
    void* ptVal;
} Data;
struct node{
    int line;
    int ruleId;
    unitType type;
    Data data;
    char* name;
    int childCnt;
    struct node* child[8];
};
#define maxLine 1000