// Красивая строка
#include <fstream>

int main()
{
    std::ifstream ifs;
    ifs.open("input.txt");

    std::ofstream ofs;
    ofs.open("output.txt");

    int k;
    std::string str;
    ifs >> k >> str;

    int len = str.length();

    if (len <= 1)
    {
        ofs << len;
        return 0;
    }

    int maxBeauty = 1;
    for (char c = 'a'; c <= 'z'; c++)
    {
        int first = 0;
        int second = 1;
        int bal = k;

        if (str[first] != c)
        {
            --bal;
        }

        if (str[second] != c)
        {
            --bal;
        }

        while (second < len)
        {
            while (bal > 0 && second + 1 < len)
            {
                ++second;
                if (str[second] != c)
                {
                    --bal;
                }
            }
            maxBeauty = std::max(maxBeauty, second - first + 1);

            while (bal <= 0 && second < len)
            {
                if (str[first] != c)
                {
                    ++bal;
                }
                ++first;
            }
        }
    }
    ofs << maxBeauty;
    ifs.close();
    ofs.close();
    return 0;
}
