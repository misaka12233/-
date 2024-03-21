#include <string.h>

typedef enum unitType
{
    TOKEN_ID = 0,
    TOKEN_TYPE = 1,
    TOKEN_INT = 2,
    TOKEN_FLOAT = 3,
    TOKEN_OTHER = 4,
    SYNTAX_UNIT = 5,
    ERROR_UNIT = 255
} unitType;
typedef union Data
{
    int intVal;
    double floatVal;
    char strVal[32];
} Data;
struct node{
    int line;
    unitType type;
    Data data;
    char* name;
    int childCnt;
    struct node* child[8];
};
#define maxLine 1000