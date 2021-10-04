%{
    int isComment=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%%

#.*                         { printf("\nPreprocessor Directive: %s", yytext); }
int |
float |
char |
double |
while |
for |
do |
if |
break |
continue |
void |
switch |
case |
long |
struct |
const |
typedef |
return |
else |
goto                        { printf("\nKeyword: %s", yytext); }

"/*"                        { isComment = 1; }
"*/"                        { isComment = 0; }

{identifier}\(              { if(!isComment) printf("\nFunction:\n%s", yytext); }
\{                          { if(!isComment) printf("\nBlock Start!"); }
\}                          { if(!isComment) printf("\nBlock End!"); }
{identifier}(\[[0-9]*\])?   { if(!isComment) printf("\nIdentifier: %s", yytext);}

\".*\"                      { if(!isComment) printf("\nString: %s", yytext);}
[0-9]+                      { if(!isComment) printf("\nNumber: %s", yytext);}
\)(\;)?                     { if(!isComment) printf("\n");ECHO;printf("\n"); }
\( ECHO;

=                           { if(!isComment)printf("\nAssignment op: %s", yytext); }

\<= |
\>= |
\< |
== |
\>                          { if(!isComment) printf("\nRelop: %s", yytext); }
%%

int main(int argc,char **argv)
{
    FILE *file;
    file = fopen("program.c", "r");
    yyin = file;
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}