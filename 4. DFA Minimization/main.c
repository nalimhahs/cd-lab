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
        int temp;

        printf("Enter transition state for state %d on 0: ", i);
        scanf("%d", &temp);
        narr[temp] = 1;

        int num = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            num += narr[j] * power(2, j);
        }
        arr[i][0] = num;

        int narr2[10] = {0};
        int temp2;

        printf("Enter transition state for state %d on 1: ", i);
        scanf("%d", &temp2);
        narr2[temp2] = 1;

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

    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (result[i][0] < 0 || result[j][1] < 0)
                continue;
            if (result[i][1] == result[j][1] && result[i][2] == result[j][2])
            {
                int flag = 1;
                for (int p = 0; p < k; p++)
                {
                    if (result[p][1] == result[i][1] && result[p][2] == result[i][2])
                    {
                        if (flag)
                        {
                            flag -= 1;
                        }
                        else
                        {
                            for (int q = 0; q < k; q++)
                            {
                                if (result[q][1] == result[p][0])
                                {
                                    result[q][1] = result[i][0];
                                }
                                if (result[q][2] == result[p][0])
                                {
                                    result[q][2] = result[i][0];
                                }
                            }
                            result[p][0] = -1;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (result[i][0] == result[j][1] && result[i][1] == result[j][0] && result[i][2] == result[j][2])
            {
                result[j][0] = -1;
                result[i][1] = result[i][0];
            }
            else if (result[i][0] == result[j][2] && result[i][2] == result[j][0] && result[i][1] == result[j][1])
            {
                result[j][0] = -1;
                result[i][2] = result[i][0];
            }
        }
    }

    printf("\nMinimized DFA \n\n");
    printf("State\t0\t1\n");
    for (int i = 0; i < k; i++)
    {
        if (result[i][0] < 0)
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
