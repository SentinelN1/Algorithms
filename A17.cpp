// Гоблины и шаманы
#include <fstream>
#include <list>

int main()
{
    // std::cin >> n;
    std::ifstream is;
    std::ofstream os;
    is.open("inputA17.txt");
    os.open("outputA17.txt");
    int n;
    is >> n;
    std::list<int> goblins;
    auto it = goblins.end();
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        char mode;
        int index;
        // std::cin >> mode;
        is >> mode;
        switch (mode)
        {
        default:
            break;

        case '+':
            // std::cin >> index;
            is >> index;
            goblins.push_back(index);
            ++len;
            if (len % 2 == 0)
            {
                ++it;
            }
            break;

        case '*':
            // std::cin >> index;
            is >> index;
            // it = goblins.begin();
            // std::advance(it, (len + 1) / 2);
            goblins.insert(it, index);
            ++len;
            if (len % 2 == 1)
            {
                --it;
            }
            break;

        case '-':
            --len;
            if (len % 2 == 0)
            {
                ++it;
            }
            // std::cout << *goblins.begin() << "\n";
            os << *goblins.begin() << "\n";
            goblins.pop_front();
            break;
        }
    }
    is.close();
    os.close();
}
