#include <stdio.h>

#define MAX_S 14

char buff[MAX_S + 1];
int count[27];

int main()
{
    int i = 0;
    char flag = 0;
    for (i = 0; i < MAX_S; ++i)
        if ((scanf("%c", buff + i) != EOF) && (count[buff[i] - 'a']++ == 1))
            ++flag;

    while (flag)
    {
        if (count[buff[(i % MAX_S)] - 'a']-- == 2)
            --flag;
        if (scanf("%c", buff + (i % MAX_S)) == EOF)
            return 0;
        if (count[buff[i % MAX_S] - 'a']++ == 1)
            ++flag;
        ++i;
    }

    printf("%d\n", i);

    return 0;
}