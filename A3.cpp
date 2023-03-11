// Коллекционер Диего
#include <fstream>
#include <algorithm>
#include <set>

int main()
{
    int n, k;
    std::ifstream inf;
    inf.open("input.txt");
    inf >> n;
    std::set<int> s;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        inf >> tmp;
        s.insert(tmp);
    }

    inf >> k;
    std::ofstream outf;
    outf.open("output.txt");
    for (int i = 0; i < k; ++i)
    {
        int p;
        inf >> p;
        auto it = s.lower_bound(p);
        int count = std::distance(s.begin(), it);
        outf << count << "\n";
    }
    inf.close();
    outf.close();
    return 0;
}
