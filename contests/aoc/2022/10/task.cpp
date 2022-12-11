#include <stdio.h>

char instr[10];
int v;

int main()
{
    int interv = 20;
    int max_interv = 220;
    int cycle = 0;
    int regist = 1;
    int sum = 0;
    while (scanf("%s", instr) != EOF)
    {
        if (instr[0] == 'n')
        {
            cycle += 1;
            if (cycle == interv)
            {
                printf("%d\n", cycle * regist);
                sum += cycle * regist;
                interv += 40;
            }
        }
        else
        {
            int a;
            scanf("%d", &a);

            for (int i = 0; i < 2; ++i)
            {
                cycle += 1;
                if (cycle == interv)
                {
                    printf("%d\n", cycle * regist);
                    sum += cycle * regist;
                    interv += 40;
                }
            }

            regist += a;
        }
    }

    printf("SUM: %d\n", sum);
    return 0;
}