#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    int arr[][2] = { {7, 2},
                     {4, 4},
                     {2, 4} };
    
    int result[100][3] = {0};
    int k = 0;
    result[k++][0] = 1;    

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int v = arr[i][j], flag = 0;
            for (int p = 0; p < k; p++)
            {
                if (result[p][0] == v)
                {
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                continue;
            }
            result[k++][0] = v;
        }
    }

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
        while (j < 3)
        {
            p = p | (bin[j]*arr[j][0]);
            j++;
        }

        j = 0;
        while (j < 3)
        {
            q = q | bin[j]*arr[j][1];
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
    
    for (int i = 0; i < k; i++)
    {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }
}
