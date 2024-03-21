%locations
%{
    #include "lex.yy.c"
    #include <stdarg.h>
    void yyerror(char* msg);
    struct node* makeNode(char* name, int line, int childCnt, ...);
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
        $$ = makeNode("Program", @$.first_line, 1, $1);
        root = $$;
    }
    ;
ExtDefList : { $$ = makeNode("ExtDefList", @$.first_line, 0); }
    | ExtDef ExtDefList { $$ = makeNode("ExtDefList", @$.first_line, 2, $1, $2); }
    ;
ExtDef : Specifier ExtDecList SEMI { $$ = makeNode("ExtDef", @$.first_line, 3, $1, $2, $3); }
    | Specifier SEMI { $$ = makeNode("ExtDef", @$.first_line, 2, $1, $2); }
    | Specifier FunDec CompSt { $$ = makeNode("ExtDef", @$.first_line, 3, $1, $2, $3); }
    | error {
        errorCnt++;
        if (isErrorLine[@$.first_line] == 0)
        {
            printf("Error type: B at Line %d: Wrong extern Definition\n", @$.first_line);
            isErrorLine[@$.first_line] = 1;
        }
    }
    ;
ExtDecList : VarDec { $$ = makeNode("ExtDecList", @$.first_line, 1, $1); }
    | VarDec COMMA ExtDecList { $$ = makeNode("ExtDecList", @$.first_line, 3, $1, $2, $3); }
    ;
Specifier : TYPE { $$ = makeNode("Specifier", @$.first_line, 1, $1); }
    | StructSpecifier { $$ = makeNode("Specifier", @$.first_line, 1, $1); }
    ;
StructSpecifier : STRUCT Tag { $$ = makeNode("StructSpecifier", @$.first_line, 2, $1, $2); }
    | STRUCT OptTag LC DefList RC { $$ = makeNode("StructSpecifier", @$.first_line, 5, $1, $2, $3, $4, $5); }
    ;
OptTag :  { $$ = makeNode("OptTag", @$.first_line, 0); }
    | ID { $$ = makeNode("OptTag", @$.first_line, 1, $1); }
    ;
Tag : ID { $$ = makeNode("Tag", @$.first_line, 1, $1); }
    ;
VarDec : ID { $$ = makeNode("VarDec", @$.first_line, 1, $1); }
    | VarDec LB INT RB { $$ = makeNode("VarDec", @$.first_line, 4, $1, $2, $3, $4); }
    ;
FunDec : ID LP VarList RP { $$ = makeNode("FunDec", @$.first_line, 4, $1, $2, $3, $4); }
    | ID LP RP { $$ = makeNode("FunDec", @$.first_line, 3, $1, $2, $3); }
    ;
VarList : ParamDec COMMA VarList { $$ = makeNode("VarList", @$.first_line, 3, $1, $2, $3); }
    | ParamDec { $$ = makeNode("VarList", @$.first_line, 1, $1); }
    ;
ParamDec : Specifier VarDec { $$ = makeNode("ParamDec", @$.first_line, 2, $1, $2); }
    ;
CompSt : LC DefList StmtList RC { $$ = makeNode("CompSt", @$.first_line, 4, $1, $2, $3, $4); }
    ;
StmtList :  { $$ = makeNode("StmtList", @$.first_line, 0); }
    | Stmt StmtList { $$ = makeNode("StmtList", @$.first_line, 2, $1, $2); }
    ;
Stmt : Exp SEMI { $$ = makeNode("Stmt", @$.first_line, 2, $1, $2); }
    | CompSt { $$ = makeNode("Stmt", @$.first_line, 1, $1); }
    | RETURN Exp SEMI { $$ = makeNode("Stmt", @$.first_line, 3, $1, $2, $3); }
    | IF LP Exp RP Stmt { $$ = makeNode("Stmt", @$.first_line, 5, $1, $2, $3, $4, $5); }
    | IF LP Exp RP Stmt ELSE Stmt { $$ = makeNode("Stmt", @$.first_line, 7, $1, $2, $3, $4, $5, $6, $7); }
    | WHILE LP Exp RP Stmt { $$ = makeNode("Stmt", @$.first_line, 5, $1, $2, $3, $4, $5); }
    | error {
        for (int i = @$.first_line; i <= @$.last_line; i++)
        {
            errorCnt++;
            if (isErrorLine[i] == 0)
            {
                printf("Error type: B at Line %d: Wrong Statements\n", i);
                isErrorLine[i] = 1;
            }
        }
    }
    ;
DefList :  { $$ = makeNode("DefList", @$.first_line, 0); }
    | Def DefList { $$ = makeNode("DefList", @$.first_line, 2, $1, $2); }
    ;
Def : Specifier DecList SEMI { $$ = makeNode("Def", @$.first_line, 3, $1, $2, $3); }
    | error {
        for (int i = @$.first_line; i <= @$.last_line; i++)
        {
            errorCnt++;
            if (isErrorLine[i] == 0)
            {
                printf("Error type: B at Line %d: Wrong Statements\n", i);
                isErrorLine[i] = 1;
            }
        }
    }
    ;
DecList : Dec { $$ = makeNode("DecList", @$.first_line, 1, $1); }
    | Dec COMMA DecList { $$ = makeNode("DecList", @$.first_line, 3, $1, $2, $3); }
    ;
Dec : VarDec { $$ = makeNode("Dec", @$.first_line, 1, $1); }
    | VarDec ASSIGNOP Exp { $$ = makeNode("Dec", @$.first_line, 3, $1, $2, $3); }
    ;
Exp : Exp ASSIGNOP Exp { $$ = makeNode("Exp", @$.first_line, 3, $1, $2, $3); }
    | Exp AND Exp { $$ = makeNode("Exp", @$.first_line, 3, $1, $2, $3); }
    | Exp OR Exp { $$ = makeNode("Exp", @$.first_line, 3, $1, $2, $3); }
    | Exp RELOP Exp { $$ = makeNode("Exp", @$.first_line, 3, $1, $2, $3); }
    | Exp PLUS Exp { $$ = makeNode("Exp", @$.first_line, 3, $1, $2, $3); }
    | Exp MINUS Exp { $$ = makeNode("Exp", @$.first_line, 3, $1, $2, $3); }
    | Exp STAR Exp { $$ = makeNode("Exp", @$.first_line, 3, $1, $2, $3); }
    | Exp DIV Exp { $$ = makeNode("Exp", @$.first_line, 3, $1, $2, $3); }
    | LP Exp RP { $$ = makeNode("Exp", @$.first_line, 3, $1, $2, $3); }
    | MINUS Exp { $$ = makeNode("Exp", @$.first_line, 2, $1, $2); }
    | NOT Exp { $$ = makeNode("Exp", @$.first_line, 2, $1, $2); }
    | ID LP Args RP { $$ = makeNode("Exp", @$.first_line, 4, $1, $2, $3, $4); }
    | ID LP RP { $$ = makeNode("Exp", @$.first_line, 3, $1, $2, $3); }
    | Exp LB Exp RB { $$ = makeNode("Exp", @$.first_line, 4, $1, $2, $3, $4); }
    | Exp DOT ID { $$ = makeNode("Exp", @$.first_line, 3, $1, $2, $3); }
    | ID { $$ = makeNode("Exp", @$.first_line, 1, $1); }
    | INT { $$ = makeNode("Exp", @$.first_line, 1, $1); }
    | FLOAT { $$ = makeNode("Exp", @$.first_line, 1, $1); }
    ;
Args : Exp COMMA Args { $$ = makeNode("Args", @$.first_line, 3, $1, $2, $3); }
    | Exp { $$ = makeNode("Args", @$.first_line, 1, $1); }
    ;
%%
void yyerror(char* msg) {
    //printf("%s\n", msg);
}
struct node* makeNode(char* name, int line, int childCnt, ...)
{
    struct node* now = (struct node*)malloc(sizeof(struct node));
    now->line = line;
    now->type = SYNTAX_UNIT;
    now->name = name;
    now->childCnt = childCnt;
    va_list ap;
    va_start(ap, childCnt);
    for (int i = 0; i < childCnt; i++)
        now->child[i] = va_arg(ap, struct node*);
    return now;
}