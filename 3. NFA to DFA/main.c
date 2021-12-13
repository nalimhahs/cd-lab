#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power(int n, int p)
{
    int q = 1;
    for (int i = 0; i < p; i++)
    {
        q *= n;
    }
    return q;
}

char *convert(int num, char *res)
{
    if (num <= 0)
    {
        strcat(res, "dead");
        return res;
    }

    int bin[10] = {0};
    int i = 0, j = 0;
    while (num > 0)
    {
        bin[j++] = num % 2;
        num /= 2;
    }

    for (i = 0; i < j; i++)
    {
        if (bin[i])
        {
            char temp[10] = "", temp2[10] = "";
            strcat(temp, "q");
            sprintf(temp2, "%d", i);
            strcat(temp, temp2);
            strcat(res, temp);
            
        }
    }
    return res;
}

void main(int argc, char *argv[])
{
    int arr[10][2] = {0};
    int n;
    printf("Enter number of states: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int narr[10] = {0};
        int np, temp;
        printf("Enter number of transitions for state %d on 0: ", i);
        scanf("%d", &np);
        for (int j = 0; j < np; j++)
        {
            printf("Enter transition state for state %d on 0: ", i);
            scanf("%d", &temp);
            if (temp < 0) break;
            narr[temp] = 1;
        }
        int num = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            num += narr[j] * power(2, j);
        }
        arr[i][0] = num;

        int narr2[10] = {0};
        int np2, temp2;
        printf("Enter number of transitions for state %d on 1: ", i);
        scanf("%d", &np2);
        for (int j = 0; j < np2; j++)
        {
            printf("Enter transition state for state %d on 1: ", i);
            scanf("%d", &temp2);
            if (temp2 < 0) break;
            narr2[temp2] = 1;
        }
        int num2 = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            num2 += narr2[j] * power(2, j);
        }
        arr[i][1] = num2;
    }

    int result[100][3] = {0};
    int k = 0;
    result[k++][0] = 1;

    for (int i = 0; i < k; i++)
    {
        int bin[10] = {0};
        int v = result[i][0];
        int j = 0;

        while (v > 0)
        {
            bin[j++] = v % 2;
            v /= 2;
        }

        int p = 0, q = 0;
        j = 0;
        while (j < n)
        {
            p = p | (bin[j] * arr[j][0]);
            j++;
        }

        j = 0;
        while (j < n)
        {
            q = q | bin[j] * arr[j][1];
            j++;
        }

        result[i][1] = p;
        result[i][2] = q;

        int flag = 0;
        for (int r = 0; r < k; r++)
            if (result[r][0] == p)
                flag = 1;
        if (flag == 0)
            result[k++][0] = p;

        flag = 0;
        for (int r = 0; r < k; r++)
            if (result[r][0] == q)
                flag = 1;
        if (flag == 0)
            result[k++][0] = q;
    }

    printf("\nTransition Table of DFA \n\n");
    printf("State\t0\t1\n");
    for (int i = 0; i < k; i++)
    {
        if (result[i][0] <= 0)
            continue;
        char *a, *b, *c, d[100] = "", e[100] = "", f[100] = "";
        a = d;
        b = e;
        c = f;
        int p, q, r;
        p = result[i][0];
        q = result[i][1];
        r = result[i][2];
        a = convert(p, a);
        b = convert(q, b);
        c = convert(r, c);
        printf("%s\t%s\t%s\n", a, b, c);
    }
}
