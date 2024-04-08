%locations
%{
    #include "lex.yy.c"
    #include <stdarg.h>
    void yyerror(char* msg);
    struct node* makeNode(char* name, int ruleId, int line, int childCnt, ...);
%}

%token INT FLOAT SEMI COMMA ASSIGNOP RELOP PLUS MINUS STAR DIV AND OR DOT NOT TYPE LP RP LB RB LC RC STRUCT RETURN IF ELSE WHILE ID

%left ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LP RP LB RB DOT

%%
Program : ExtDefList {
        $$ = makeNode("Program", 1, @$.first_line, 1, $1);
        root = $$;
    }
    ;
ExtDefList : { $$ = makeNode("ExtDefList", 2, @$.first_line, 0); }
    | ExtDef ExtDefList { $$ = makeNode("ExtDefList", 3, @$.first_line, 2, $1, $2); }
    ;
ExtDef : Specifier ExtDecList SEMI { $$ = makeNode("ExtDef", 4, @$.first_line, 3, $1, $2, $3); }
    | Specifier SEMI { $$ = makeNode("ExtDef", 5, @$.first_line, 2, $1, $2); }
    | Specifier FunDec CompSt { $$ = makeNode("ExtDef", 6, @$.first_line, 3, $1, $2, $3); }
    | Specifier FunDec SEMI { $$ = makeNode("ExtDef", 7, @$.first_line, 3, $1, $2, $3); }
    | error {
        errorCnt++;
        if (isErrorLine[@$.first_line] == 0)
        {
            printf("Error type: B at Line %d: Wrong extern Definition.\n", @$.first_line);
            isErrorLine[@$.first_line] = 1;
        }
    }
    ;
ExtDecList : VarDec { $$ = makeNode("ExtDecList", 8, @$.first_line, 1, $1); }
    | VarDec COMMA ExtDecList { $$ = makeNode("ExtDecList", 9, @$.first_line, 3, $1, $2, $3); }
    ;
Specifier : TYPE { $$ = makeNode("Specifier", 10, @$.first_line, 1, $1); }
    | StructSpecifier { $$ = makeNode("Specifier", 11, @$.first_line, 1, $1); }
    ;
StructSpecifier : STRUCT Tag { $$ = makeNode("StructSpecifier", 12, @$.first_line, 2, $1, $2); }
    | STRUCT OptTag LC DefList RC { $$ = makeNode("StructSpecifier", 13, @$.first_line, 5, $1, $2, $3, $4, $5); }
    ;
OptTag :  { $$ = makeNode("OptTag", 14, @$.first_line, 0); }
    | ID { $$ = makeNode("OptTag", 15, @$.first_line, 1, $1); }
    ;
Tag : ID { $$ = makeNode("Tag", 16, @$.first_line, 1, $1); }
    ;
VarDec : ID { $$ = makeNode("VarDec", 17, @$.first_line, 1, $1); }
    | VarDec LB INT RB { $$ = makeNode("VarDec", 18, @$.first_line, 4, $1, $2, $3, $4); }
    ;
FunDec : ID LP VarList RP { $$ = makeNode("FunDec", 19, @$.first_line, 4, $1, $2, $3, $4); }
    | ID LP RP { $$ = makeNode("FunDec", 20, @$.first_line, 3, $1, $2, $3); }
    ;
VarList : ParamDec COMMA VarList { $$ = makeNode("VarList", 21, @$.first_line, 3, $1, $2, $3); }
    | ParamDec { $$ = makeNode("VarList", 22, @$.first_line, 1, $1); }
    ;
ParamDec : Specifier VarDec { $$ = makeNode("ParamDec", 23, @$.first_line, 2, $1, $2); }
    ;
CompSt : LC DefList StmtList RC { $$ = makeNode("CompSt", 24, @$.first_line, 4, $1, $2, $3, $4); }
    ;
StmtList :  { $$ = makeNode("StmtList", 25, @$.first_line, 0); }
    | Stmt StmtList { $$ = makeNode("StmtList", 26, @$.first_line, 2, $1, $2); }
    ;
Stmt : Exp SEMI { $$ = makeNode("Stmt", 27, @$.first_line, 2, $1, $2); }
    | CompSt { $$ = makeNode("Stmt", 28, @$.first_line, 1, $1); }
    | RETURN Exp SEMI { $$ = makeNode("Stmt", 29, @$.first_line, 3, $1, $2, $3); }
    | IF LP Exp RP Stmt { $$ = makeNode("Stmt", 30, @$.first_line, 5, $1, $2, $3, $4, $5); }
    | IF LP Exp RP Stmt ELSE Stmt { $$ = makeNode("Stmt", 31, @$.first_line, 7, $1, $2, $3, $4, $5, $6, $7); }
    | WHILE LP Exp RP Stmt { $$ = makeNode("Stmt", 32, @$.first_line, 5, $1, $2, $3, $4, $5); }
    | error {
        for (int i = @$.first_line; i <= @$.last_line; i++)
        {
            errorCnt++;
            if (isErrorLine[i] == 0)
            {
                printf("Error type: B at Line %d: Wrong Statements.\n", i);
                isErrorLine[i] = 1;
            }
        }
    }
    ;
DefList :  { $$ = makeNode("DefList", 33, @$.first_line, 0); }
    | Def DefList { $$ = makeNode("DefList", 34, @$.first_line, 2, $1, $2); }
    ;
Def : Specifier DecList SEMI { $$ = makeNode("Def", 35, @$.first_line, 3, $1, $2, $3); }
    | error {
        for (int i = @$.first_line; i <= @$.last_line; i++)
        {
            errorCnt++;
            if (isErrorLine[i] == 0)
            {
                printf("Error type: B at Line %d: Wrong Statements.\n", i);
                isErrorLine[i] = 1;
            }
        }
    }
    ;
DecList : Dec { $$ = makeNode("DecList", 36, @$.first_line, 1, $1); }
    | Dec COMMA DecList { $$ = makeNode("DecList", 37, @$.first_line, 3, $1, $2, $3); }
    ;
Dec : VarDec { $$ = makeNode("Dec", 38, @$.first_line, 1, $1); }
    | VarDec ASSIGNOP Exp { $$ = makeNode("Dec", 39, @$.first_line, 3, $1, $2, $3); }
    ;
Exp : Exp ASSIGNOP Exp { $$ = makeNode("Exp", 40, @$.first_line, 3, $1, $2, $3); }
    | Exp AND Exp { $$ = makeNode("Exp", 41, @$.first_line, 3, $1, $2, $3); }
    | Exp OR Exp { $$ = makeNode("Exp", 42, @$.first_line, 3, $1, $2, $3); }
    | Exp RELOP Exp { $$ = makeNode("Exp", 43, @$.first_line, 3, $1, $2, $3); }
    | Exp PLUS Exp { $$ = makeNode("Exp", 44, @$.first_line, 3, $1, $2, $3); }
    | Exp MINUS Exp { $$ = makeNode("Exp", 45, @$.first_line, 3, $1, $2, $3); }
    | Exp STAR Exp { $$ = makeNode("Exp", 46, @$.first_line, 3, $1, $2, $3); }
    | Exp DIV Exp { $$ = makeNode("Exp", 47, @$.first_line, 3, $1, $2, $3); }
    | LP Exp RP { $$ = makeNode("Exp", 48, @$.first_line, 3, $1, $2, $3); }
    | MINUS Exp { $$ = makeNode("Exp", 49, @$.first_line, 2, $1, $2); }
    | NOT Exp { $$ = makeNode("Exp", 50, @$.first_line, 2, $1, $2); }
    | ID LP Args RP { $$ = makeNode("Exp", 51, @$.first_line, 4, $1, $2, $3, $4); }
    | ID LP RP { $$ = makeNode("Exp", 52, @$.first_line, 3, $1, $2, $3); }
    | Exp LB Exp RB { $$ = makeNode("Exp", 53, @$.first_line, 4, $1, $2, $3, $4); }
    | Exp DOT ID { $$ = makeNode("Exp", 54, @$.first_line, 3, $1, $2, $3); }
    | ID { $$ = makeNode("Exp", 55, @$.first_line, 1, $1); }
    | INT { $$ = makeNode("Exp", 56, @$.first_line, 1, $1); }
    | FLOAT { $$ = makeNode("Exp", 57, @$.first_line, 1, $1); }
    ;
Args : Exp COMMA Args { $$ = makeNode("Args", 58, @$.first_line, 3, $1, $2, $3); }
    | Exp { $$ = makeNode("Args", 59, @$.first_line, 1, $1); }
    ;
%%
void yyerror(char* msg) {
    //printf("%s\n", msg);
}
struct node* makeNode(char* name, int ruleId, int line, int childCnt, ...)
{
    struct node* now = (struct node*)malloc(sizeof(struct node));
    now->line = line;
    now->ruleId = ruleId;
    now->type = SYNTAX_UNIT;
    now->name = name;
    now->childCnt = childCnt;
    memset(now->data.strVal, 0, sizeof(now->data.strVal));
    va_list ap;
    va_start(ap, childCnt);
    for (int i = 0; i < childCnt; i++)
        now->child[i] = va_arg(ap, struct node*);
    return now;
}