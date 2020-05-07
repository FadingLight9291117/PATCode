/*
    暂时搁置
*/
#include <stdio.h>
const char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int findNumber(char c)
{
    for (int i = 0; i < 36; i++)
    {
        if (c == digit[i])
            return i;
    }
    return -1;
}

int radixTranslate(char *digits, int n, int radix)
{
    
}

int main()
{
    char n1[10], n2[10];
    int tag, radix;
    char temp;
    int i = 0;
    while (temp = getchar())
    {
        if (temp == ' ')
        {
            n1[i] = '\0';
            break;
        }
        n1[i++] = temp;
    }
    i = 0;
    while (temp = getchar())
    {
        if (temp == ' ')
        {
            n2[i] = '\0';
            break;
        }
        n2[i++] = temp;
    }
    scanf("%d %d", &tag, &radix);
    // for (int i = 2; i < )
    return 0;
}