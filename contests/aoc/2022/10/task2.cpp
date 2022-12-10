#include <stdio.h>
#include <algorithm>

char instr[10];
int v;

void draw_pixel(int c, int r)
{
    c = (c % 40);

    if (std::abs(c - r) < 2)
    {
        printf("#");
    }
    else
    {
        printf(".");
    }
}

int main()
{
    int interv = 40;
    int max_interv = 220;
    int cycle = 0;
    int regist = 1;
    int sum = 0;
    while (scanf("%s", instr) != EOF)
    {
        if (instr[0] == 'n')
        {
            draw_pixel(cycle, regist);
            cycle += 1;
            if (cycle == interv)
            {
                printf("\n");
                interv += 40;
            }
        }
        else
        {
            int a;
            scanf("%d", &a);

            for (int i = 0; i < 2; ++i)
            {
                draw_pixel(cycle, regist);
                cycle += 1;
                if (cycle == interv)
                {
                    printf("\n");
                    interv += 40;
                }
            }

            regist += a;
        }
    }

    printf("SUM: %d\n", sum);
    return 0;
}