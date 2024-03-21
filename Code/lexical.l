%option yylineno
%{
    #define YYSTYPE struct node*
    #include "syntax.tab.h"
    #include "head.h"
    int errorCnt = 0;
    int isErrorLine[maxLine];
    struct node* root;
    void makeTokenNode(char* name, unitType type, Data data);
    Data data;
    int yycolumn = 1;
    #define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; \
    yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng; \
    memset(data.strVal, 0, sizeof(data.strVal)); \
    strcpy(data.strVal, yytext);
%}
int8 0[0-7]+
int10 0|[1-9][0-9]*
int16 0x[0-9a-fA-F]+
digit0 [0-9]*
digit1 [0-9]+
float {digit1}\.{digit1}
efloat ({digit0}\.{digit1}|{digit1}\.{digit0})[Ee][+-]?{digit1}
semi ;
comma ,
assignop =
relop >|<|>=|<=|==|!=
plus \+
minus -
star \*
div \/
and &&
or \|\|
dot \.
not !
type int|float
lp \(
rp \)
lb \[
rb \]
lc \{
rc \}
%%
{int8} { 
    memset(data.strVal, 0, sizeof(data.strVal));
    data.intVal = (int)strtol(yytext, NULL, 8);
    makeTokenNode("INT", TOKEN_INT, data); 
    return INT; 
    }
{int10} { 
    memset(data.strVal, 0, sizeof(data.strVal));
    data.intVal = (int)strtol(yytext, NULL, 10);
    makeTokenNode("INT", TOKEN_INT, data); 
    return INT; 
    }
{int16} { 
    memset(data.strVal, 0, sizeof(data.strVal));
    data.intVal = (int)strtol(yytext, NULL, 16);
    makeTokenNode("INT", TOKEN_INT, data); 
    return INT; 
    }
{float}|{efloat} { 
    memset(data.strVal, 0, sizeof(data.strVal));
    data.floatVal = strtod(yytext, NULL);
    makeTokenNode("FLOAT", TOKEN_FLOAT, data); 
    return FLOAT; 
    }
{semi} { makeTokenNode("SEMI", TOKEN_OTHER, data); return SEMI; }
{comma} { makeTokenNode("COMMA", TOKEN_OTHER, data); return COMMA; }
{assignop} { makeTokenNode("ASSIGNOP", TOKEN_OTHER, data); return ASSIGNOP; }
{relop} { makeTokenNode("RELOP", TOKEN_OTHER, data); return RELOP; }
{plus} { makeTokenNode("PLUS", TOKEN_OTHER, data); return PLUS; }
{minus} { makeTokenNode("MINUS", TOKEN_OTHER, data); return MINUS; }
{star} { makeTokenNode("STAR", TOKEN_OTHER, data); return STAR; }
{div} { makeTokenNode("DIV", TOKEN_OTHER, data); return DIV; }
{and} { makeTokenNode("AND", TOKEN_OTHER, data); return AND; }
{or} { makeTokenNode("OR", TOKEN_OTHER, data); return OR; }
{dot} { makeTokenNode("DOT", TOKEN_OTHER, data); return DOT; }
{not} { makeTokenNode("NOT", TOKEN_OTHER, data); return NOT; }
{type} { makeTokenNode("TYPE", TOKEN_TYPE, data); return TYPE; }
{lp} { makeTokenNode("LP", TOKEN_OTHER, data); return LP; }
{rp} { makeTokenNode("RP", TOKEN_OTHER, data); return RP; }
{lb} { makeTokenNode("LB", TOKEN_OTHER, data); return LB; }
{rb} { makeTokenNode("RB", TOKEN_OTHER, data); return RB; }
{lc} { makeTokenNode("LC", TOKEN_OTHER, data); return LC; }
{rc} { makeTokenNode("RC", TOKEN_OTHER, data); return RC; }
struct { makeTokenNode("STRUCT", TOKEN_OTHER, data); return STRUCT; }
return { makeTokenNode("RETURN", TOKEN_OTHER, data); return RETURN; }
if { makeTokenNode("IF", TOKEN_OTHER, data); return IF; }
else { makeTokenNode("ELSE", TOKEN_OTHER, data); return ELSE; }
while { makeTokenNode("WHILE", TOKEN_OTHER, data); return WHILE; }
[a-zA-Z_][a-zA-Z0-9_]* { makeTokenNode("ID", TOKEN_ID, data); return ID; }
"//" {
    char c = input();
    while (c != 0 && c != '\n') 
        c = input();
}
"/*" {
    char c1 = input(), c2 = input();
    while (c1 != 0 && c2 != 0 && (c1 != '*' || c2 != '/')) 
        c1 = c2, c2 = input();
}
\n { yycolumn = 1; }
" "|\t|\r {}
[0-9][0-9a-zA-Z]* {
    errorCnt++;
    if (isErrorLine[yylineno] == 0)
    {
        printf("Error type: A at Line %d: Wrong Int Number \'%s\'\n.", yylineno, yytext);
        isErrorLine[yylineno] = 1;
    }
    return INT;
}
[0-9][0-9a-zA-Z\.]*|\.[0-9][0-9a-zA-Z\.]* {
    errorCnt++;
    if (isErrorLine[yylineno] == 0)
    {
        printf("Error type: A at Line %d: Wrong Float Number \'%s\'\n.", yylineno, yytext);
        isErrorLine[yylineno] = 1;
    }
    return FLOAT;
}
. {
    errorCnt++;
    if (isErrorLine[yylineno] == 0)
    {
        printf("Error type: A at Line %d: Myterious characters \'%s\'\n.", yylineno, yytext);
        isErrorLine[yylineno] = 1;
    }
}
%%
void makeTokenNode(char* name, unitType type, Data data)
{
    struct node* now = (struct node*)malloc(sizeof(struct node));
    now->line = yylineno;
    now->type = type;
    now->data = data;
    now->name = name;
    now->childCnt = 0;
    yylval = now;
}