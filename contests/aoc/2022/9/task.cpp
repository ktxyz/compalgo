#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>

char D;
int A;
std::vector<std::pair<int, int>> posP;
std::set<std::pair<int, int>> pos;

int k;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main()
{
    int LENGTH = 10;
    for (int i = 0; i < LENGTH; ++i)
        posP.push_back({0, 0});
    pos.insert({0, 0});
    while (scanf("%c %d\n", &D, &A) != EOF)
    {
        switch (D)
        {
        case 'L':
            k = 1;
            break;
        case 'R':
            k = 0;
            break;
        case 'U':
            k = 3;
            break;
        case 'D':
            k = 2;
            break;
        }

        for (int i = 0; i < A; ++i)
        {
            posP[0].first += dx[k];
            posP[0].second += dy[k];
            for (int e = 1; e < LENGTH; ++e)
            {
                auto &posH = posP[e - 1];
                auto &posT = posP[e];

                int distX = std::abs(posH.first - posT.first);
                int distY = std::abs(posH.second - posT.second);
                bool sameR = posH.first == posT.first;
                bool sameC = posH.second == posT.second;

                if (sameR || sameC)
                {
                    if (distX > 1)
                    {
                        posT.first += (posH.first > posT.first ? 1 : -1);
                    }
                    if (distY > 1)
                    {
                        posT.second += (posH.second > posT.second ? 1 : -1);
                    }
                }
                else if (distX > 1 || distY > 1)
                {
                    posT.first += (posH.first > posT.first ? 1 : -1);
                    posT.second += (posH.second > posT.second ? 1 : -1);
                }

                if (e == (LENGTH - 1))
                {
                    pos.insert(posT);
                }
            }
        }
    }
    printf("%lu\n", pos.size());
    return 0;
}