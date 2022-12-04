#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

bool charMap[256];
int carryChar[256];
std::vector<std::string> vec;

int answer1()
{
    int answ = 0;
    for (auto &s : vec)
    {
        for (int i = 0; i < 256; ++i)
            charMap[i] = false;

        size_t l = s.size() / 2;
        for (int i = 0; i < l; ++i)
        {
            char c = s[i];
            charMap[c - 'A'] = true;
        }

        for (int i = l; i < s.size(); ++i)
        {
            char c = s[i];
            if (charMap[c - 'A'])
            {
                if (c >= 'a' && c <= 'z')
                    answ += c - 'a' + 1;
                if (c >= 'A' && c <= 'Z')
                    answ += c - 'A' + 27;
                charMap[c - 'A'] = false;
            }
        }
    }
    return answ;
}

int answer2()
{
    int answ = 0;
    for (int i = 0; i < vec.size(); i += 3)
    {
        char groupC = 'a';
        for (int i = 0; i < 256; ++i)
            carryChar[i] = 0;
        for (int j = 0; j < 3; ++j)
        {
            for (int i = 0; i < 256; ++i)
                charMap[i] = 0;
            auto &s = vec[i + j];

            for (int k = 0; k < s.size(); ++k)
            {
                char c = s[k];
                if (!charMap[c])
                {
                    ++carryChar[c];
                }
                charMap[c] = true;
            }
        }

        for (char k = 'A'; k <= 'z'; ++k)
        {
            if (carryChar[k] == 3)
            {
                groupC = k;
                break;
            }
        }

        char c = groupC;
        if (c >= 'a' && c <= 'z')
            answ += c - 'a' + 1;
        if (c >= 'A' && c <= 'Z')
            answ += c - 'A' + 27;
    }
    return answ;
}

int main()
{
    std::string in;
    while (std::cin >> in)
        vec.push_back(in);

    std::cout << answer1() << std::endl;
    std::cout << answer2() << std::endl;
    return 0;
}