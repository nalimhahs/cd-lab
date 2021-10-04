#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isOperator(char c) { return c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '%'; }

int isKeyword(char buffer[])
{
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while"};
    int i, flag = 0;
    for (i = 0; i < 32; ++i)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    char ch, buffer[15];
    FILE *fp;
    int i, j = 0;
    fp = fopen("program.c", "r");
    if (fp == NULL)
    {
        printf("Error while opening the file\n");
        exit(0);
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isalpha(ch) || ch == '_')
        {
            buffer[j++] = ch;
            while ((ch = fgetc(fp)) != EOF && (isalpha(ch) || isdigit(ch) || ch == '_'))
            {
                buffer[j++] = ch;
            }
            buffer[j] = '\0';
            if (isKeyword(buffer))
            {
                printf("%s is a keyword\n", buffer);
            }
            else
            {
                printf("%s is an identifier\n", buffer);
            }
            j = 0;
        }
        else if (isdigit(ch))
        {
            buffer[j++] = ch;
            while ((ch = fgetc(fp)) != EOF && isdigit(ch))
            {
                buffer[j++] = ch;
            }
            buffer[j] = '\0';
            printf("%s is an integer\n", buffer);
            j = 0;
        }
        else if (isOperator(ch))
        {
            printf("%c is an operator\n", ch);
        }
        else if (ch == ' ' || ch == '\n' || ch == '\t' || ch == ';')
        {
            continue;
        }
        else
        {
            printf("%c is an invalid character\n", ch);
        }
    }
    fclose(fp);
    return 0;
}