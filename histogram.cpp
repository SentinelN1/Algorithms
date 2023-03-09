#include <fstream>
#include <map>

int main()
{
    std::ifstream is;
    is.open("input.txt");
    if (is)
    {

        std::ofstream os;
        os.open("output.txt");
        if (os)
        {
            int max = 0;
            std::map<char, int> histogram;
            while (!is.bad())
            {
                char tmp;
                is >> tmp;
                if (is.eof())
                {
                    break;
                }
                histogram[tmp]++;
                max = std::max(max, histogram[tmp]);
            }
            is.close();

            for (size_t i = max; i > 0; --i)
            {
                for (auto j : histogram)
                {
                    if (j.second >= i)
                    {
                        os << "#";
                    }
                    else
                    {
                        os << " ";
                    }
                }
                os << "\n";
            }
            for (auto j : histogram)
            {
                os << j.first;
            }
            os << "\n";

            os.close();
        }
    }
    return 0;
}