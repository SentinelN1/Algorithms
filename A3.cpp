// Коллекционер Диего
#include <fstream>
#include <algorithm>
#include <vector>

int main()
{
    int n, k;
    std::ifstream is;
    std::ofstream os;
    is.open("input.txt");
    os.open("output.txt");
    is >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        is >> vec[i];
    }
    std::sort(vec.begin(), vec.end());
    std::unique(vec.begin(), vec.end());

    is >> k;
    for (int i = 0; i < k; ++i)
    {
        int p;
        is >> p;
        auto it = std::lower_bound(vec.begin(), vec.end(), p);
        int count = std::distance(vec.begin(), it);
        os << count << "\n";
    }
    is.close();
    os.close();
    return 0;
}
