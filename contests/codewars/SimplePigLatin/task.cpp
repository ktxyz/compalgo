#include <string>
#include <sstream>
#include <vector>
#include <iostream>

std::string pig_it(std::string str)
{
    std::string output;
    std::stringstream ss(str);
    std::string w;

    while (std::getline(ss, w, ' '))
    {
        bool noAlpha = true;
        for (auto &c : w)
        {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                noAlpha = false;
                break;
            }
        }
        if (noAlpha)
        {
            output += w;
            output += ' ';
            continue;
        }

        if (w.size() == 0)
            continue;

        char a = w[0];
        w = w.substr(1, w.length() - 1);
        w += a;
        w += "ay";

        output += w;
        output += ' ';
    }

    output.pop_back();
    return output;
}

int main()
{
    std::cout << "WTF" << std::endl;
    std::cout << pig_it("Pig latin is cool") << std::endl;
    return 0;
}