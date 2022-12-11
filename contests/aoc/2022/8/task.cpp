#include <stdio.h>
#include <string.h>

constexpr int MAX_L = 101;

bool vis[MAX_L][MAX_L];
char grid[MAX_L][MAX_L];
long long score[MAX_L][MAX_L];

#define MAX(a, b) (a > b ? a : b)

int main()
{
    int l = 0;
    while (scanf("%s", grid[l++]) != EOF)
        ;
    int w = strlen(grid[0]);
    printf("%d %d\n", --l, w);

    for (int i = 0; i < l; ++i)
        for (int j = 0; j < w; ++j)
            score[i][j] = 1;

    for (int x = 0; x < w; ++x)
    {
        int max_1 = -1;
        int max_2 = -1;

        for (int y = 0; y < l; ++y)
        {
            int y1 = y;
            int y2 = l - y - 1;

            if ((grid[y1][x] - '0') > max_1)
            {
                vis[y1][x] = true;
                max_1 = MAX(max_1, (grid[y1][x] - '0'));
            }

            if ((grid[y2][x] - '0') > max_2)
            {
                vis[y2][x] = true;
                max_2 = MAX(max_2, (grid[y2][x] - '0'));
            }
        }
    }

    for (int x = 0; x < l; ++x)
    {
        int max_1 = -1;
        int max_2 = -1;
        for (int y = 0; y < w; ++y)
        {
            int y1 = y;
            int y2 = w - y - 1;

            if ((grid[x][y1] - '0') > max_1)
            {
                vis[x][y1] = true;
                max_1 = MAX(max_1, (grid[x][y1] - '0'));
            }
            if ((grid[x][y2] - '0') > max_2)
            {
                vis[x][y2] = true;
                max_2 = MAX(max_2, (grid[x][y2] - '0'));
            }
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    for (int y = 0; y < l; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            // printf("%dx%d[%c]\n", x, y, grid[y][x]);
            for (int k = 0; k < 4; ++k)
            {
                int h = 1;
                int p = 0;
                int nx = x + dx[k] * h;
                int ny = y + dy[k] * h;
                while (((nx) < w) && ((nx) >= 0) && ((ny) < l) && ((ny) >= 0))
                {
                    if (grid[ny][nx] >= grid[y][x])
                    {
                        // printf("\t\t[%c]\n", grid[ny][nx]);
                        p = h;
                        break;
                    }
                    p = h++;
                    nx = x + dx[k] * h;
                    ny = y + dy[k] * h;
                }

                // printf("\t%d = %d\n", k, p);
                score[y][x] *= p;
            }
        }
    }

    int a = 0;
    long long b = 0;
    for (int i = 0; i < l; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            // printf(" %lld ", score[i][j]);
            a += vis[i][j] == true;
            b = MAX(score[i][j], b);
        }
        // printf("\n");
    }

    printf("%d %lld\n", a, b);
    return 0;
}