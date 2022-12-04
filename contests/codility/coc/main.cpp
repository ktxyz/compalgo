#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int colorToV(char c)
{
    switch (c)
    {
    case 'R':
        return 0;
        break;
    case 'G':
        return 1;
        break;
    case 'B':
        return 2;
    case 'W':
        return 3;
    default:
        return 0;
    }
}

int findColorRot(string &s, char C, bool rev = false)
{
    int fIdx = -1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == C)
        {
            fIdx = i;
            break;
        }
    }
    // std::cout << s << " - " << C << " - " << rev << " = ";

    int sIdx = 1;
    if (rev)
        sIdx = 3;

    // std::cout << fIdx << " - " << sIdx << " " << std::endl;

    int diff = abs(sIdx - fIdx);
    return min(diff, 4 - diff);
}

char getOpposite(string &s, char C)
{
    int fIdx = -1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == C)
        {
            fIdx = i;
            break;
        }
    }

    // std::cout << "OPP FOUND: " << C << " - " << fIdx << " - " << (fIdx + 2) % 4 << " - " << s[(fIdx + 2) % 4] << std::endl;
    if (fIdx == -1)
    {
        throw(1);
    }
    return s[(fIdx + 2) % 4];
}

int solution(vector<string> &A)
{
    char colors[] = {'R', 'G', 'B', 'W'};
    vector<int> a[4];

    for (int i = 0; i < 4; ++i)
    {
        a[colorToV(colors[i])].push_back(findColorRot(A[0], colors[i]));
    }

    for (int k = 1; k < A.size(); ++k)
    {
        for (int i = 0; i < 4; ++i)
        {
            int prev = a[colorToV(getOpposite(A[k], colors[i]))][k - 1];
            int curr = findColorRot(A[k], colors[i]);
            // std::cout << "FINDING FROM " << colors[i] << " TO " << getOpposite(A[k], colors[i]) << std::endl;
            // std::cout << "PREVIOUS VALUE: " << prev << std::endl;
            // std::cout << "MY CHANGE: " << curr << std::endl;
            a[colorToV(colors[i])].push_back(prev + curr);
        }
    }

    int answer = 1e8;
    for (int i = 0; i < 4; ++i)
        answer = min(answer, a[i].back());
    return answer;
}

int main()
{
    vector<string> A = {
        "RBGW", "GBRW", "RWGB", "GBRW"};
    std::cout << solution(A) << std::endl;
    return 0;
}