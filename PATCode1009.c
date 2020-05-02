/*
    1. double数组初始化时，要用0.0,否则或出错。
    2. 会存在系数相乘为0的情况，但我觉得不太可能，除非其中一个系数为0，
        但输入的系数为0，没有意义啊；但是不考虑的话，测试用例有一个会
        出错，没办法。
*/
#include <stdio.h>
int main()
{
    int n1, n2, e;
    double a1[1001] = {0}, a2[1001] = {0.0};
    double result[2001] = {0.0};
    int size = 0;
    // 输入
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &e);
        scanf("%lf", a1 + e);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &e);
        scanf("%lf", a2 + e);
    }

    // 计算
    for (int i = 0; i <= 1000; i++)
    {
        if (a1[i] != 0.0)
        {
            for (int j = 0; j <= 1000; j++)
            {
                if (a2[j] != 0.0)
                {
                    int e1 = i + j;
                    double c1 = a1[i] * a2[j];
                    if (result[e1] == 0.0)
                        size++;
                    result[e1] += c1;
                    if (result[e1] == 0.0)
                        size--;
                }
            }
        }
    }

    // 输出
    printf("%d", size);
    for (int i = 2000; i >= 0; i--)
    {
        if (result[i] != 0.0)
        {
            printf(" %d", i);
            printf(" %.1lf", result[i]);
        }
    }
    return 0;
}