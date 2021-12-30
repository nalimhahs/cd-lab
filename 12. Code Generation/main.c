#include <stdio.h>
#include <stdio.h>
#include <string.h>

void main()
{
    char icode[10][30], str[20], opr[10];
    char * line = NULL;
    int i = 0, max = 0;
    size_t len = 0;

    int c;
    FILE *file;
    file = fopen("3ac", "r");
    if (file)
    {
        while ((c = getline(&line, &len, file)) != EOF)
        {
            strcpy(icode[i], line);
            i++;
        }
        fclose(file);
    }
    else
        printf("File not found\n");
    max = i;
    i = 0;
    printf("Generated Code:\n");
    do
    {
        strcpy(str, icode[i]);
        switch (str[3])
        {
        case '+':
            strcpy(opr, "ADD");
            break;
        case '-':
            strcpy(opr, "SUB");
            break;
        case '*':
            strcpy(opr, "MUL");
            break;
        case '/':
            strcpy(opr, "DIV");
            break;
        }
        printf("\nMOV %c, R%d", str[2], i);
        printf("\n%s %c, R%d", opr, str[4], i);
        printf("\nMOV R%d, %c", i, str[0]);
        i++;
    } while (i < max);
    printf("\n");
}