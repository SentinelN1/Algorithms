#include <iostream>
#include <vector>
#include <map>

typedef int ULLI;

int main()
{
    ULLI n;
    ULLI w = 7;
    ULLI ans = -1;

    std::cin >> n;
    std::vector<ULLI> marks(n);
    std::map<ULLI, ULLI> count;

    for (ULLI i = 0; i < n; i++)
    {
        std::cin >> marks[i];
        count[marks[i]]++;

        if (i >= w)
        {
            count[marks[i - w]]--;
        }

        if (i >= w - 1 && count[2] == 0 && count[3] == 0)
        {
            ans = std::max(ans, count[5]);
        }

        // for (ULLI mark = 2; mark <= 5; mark++)
        // {
        //     std::cout << count[mark] << " ";
        // }
        // std::cout << "\n";
    }

    std::cout << ans;

    return 0;
}