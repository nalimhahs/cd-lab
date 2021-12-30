#include <stdio.h>
#include <string.h>

int k = 0, z = 0, i = 0, j = 0, input_len = 0;
char input_str[16], ac[20], stack[15], action[10];

void check();

int main()
{

    printf("GRAMMAR is: \n E->E+E \n E->E*E \n E->(E) \n E->id");
    printf("\nEnter input string: ");
    scanf("%s", input_str);
    input_len = strlen(input_str);
    strcpy(action, "SHIFT->");
    puts("Stack \t\tInput \t\t\tAction");
    for (k = 0, i = 0; j < input_len; k++, i++, j++)
    {
        if (input_str[j] == 'i' && input_str[j + 1] == 'd')
        {
            stack[i] = input_str[j];
            stack[i + 1] = input_str[j + 1];
            stack[i + 2] = '\0';
            input_str[j] = ' ';
            input_str[j + 1] = ' ';
            printf("$%s\t\t%s$\t\t%sid\n", stack, input_str, action);
            check();
        }
        else
        {
            stack[i] = input_str[j];
            stack[i + 1] = '\0';
            input_str[j] = ' ';
            printf("$%s\t\t%s$\t\t%sSymbol\n", stack, input_str, action);
            check();
        }
    }
}

void check()
{
    strcpy(ac, "REDUCE TO E");
    for (z = 0; z < input_len; z++)
        if (stack[z] == 'i' && stack[z + 1] == 'd')
        {
            stack[z] = 'E';
            stack[z + 1] = '\0';
            printf("$%s\t\t%s$\t\t%s\n", stack, input_str, ac);
            j++;
        }
    for (z = 0; z < input_len; z++)
        if (stack[z] == 'E' && stack[z + 1] == '+' && stack[z + 2] == 'E')
        {
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("$%s\t\t%s$\t\t%s\n", stack, input_str, ac);
            i = i - 2;
        }
    for (z = 0; z < input_len; z++)
        if (stack[z] == 'E' && stack[z + 1] == '*' && stack[z + 2] == 'E')
        {
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 1] = '\0';
            printf("$%s\t\t%s$\t\t%s\n", stack, input_str, ac);
            i = i - 2;
        }
    for (z = 0; z < input_len; z++)
        if (stack[z] == '(' && stack[z + 1] == 'E' && stack[z + 2] == ')')
        {
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 1] = '\0';
            printf("$%s\t\t%s$\t\t%s\n", stack, input_str, ac);
            i = i - 2;
        }
}