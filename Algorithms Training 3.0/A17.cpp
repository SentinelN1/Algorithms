// Гоблины и шаманы
#include <fstream>
#include <queue>

int main()
{
    std::ifstream is;
    is.open("input.txt");

    std::ofstream os;
    os.open("output.txt");

    int n;
    is >> n;

    std::deque<int> first;
    int l1 = 0;

    std::deque<int> second;
    int l2 = 0;

    for (int i = 0; i < n; i++)
    {
        char mode;
        int index;
        is >> mode;
        switch (mode)
        {
        case '+':
            is >> index;
            if (first.empty())
            {
                first.push_back(index);
                ++l1;
                continue;
            }
            second.push_back(index);
            ++l2;
            if (l2 > l1)
            {
                first.push_back(second.front());
                second.pop_front();
                ++l1;
                --l2;
            }
            break;

        case '*':
            is >> index;
            if (l1 - l2 >= 1)
            {
                second.push_front(index);
                ++l2;
                continue;
            }
            first.push_back(index);
            ++l1;
            break;

        case '-':
            os << first.front() << "\n";
            first.pop_front();
            --l1;
            if (l1 < l2)
            {
                first.push_back(second.front());
                second.pop_front();
                ++l1;
                --l2;
            }

            break;
        }
    }
    is.close();
    os.close();
}
