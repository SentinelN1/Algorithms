#include <iostream>
#include <vector>

int main()
{
    int k, n;
    std::cin >> k >> n;
    std::vector<int> trains(n);
    std::vector<int> depos(k);
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        int in, out;
        std::cin >> in >> out;
        for (int j = 0; j < k; j++)
        {
            if (depos[j] < in)
            {
                trains[i] = j + 1;
                depos[j] = out;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            std::cout << 0 << " " << i + 1;
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << trains[i] << " ";
    }
    return 0;
}
