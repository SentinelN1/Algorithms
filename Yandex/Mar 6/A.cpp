#include <iostream>
// #include <fstream>

typedef unsigned long long int ULL;

bool solve(ULL x, ULL y, ULL z)
{
    if (x + y + z == 1)
    {
        return true;
    }

    bool a, b, c;
    ULL dx = std::min(y, z);
    if (dx > 0)
    {
        a = solve(x + dx, y - dx, z - dx);
    }

    ULL dy = std::min(x, z);
    if (dy > 0)
    {
        b = solve(x - dy, y + dy, z - dy);
    }

    ULL dz = std::min(x, y);
    if (dz > 0)
    {
        c = solve(x - dz, y - dz, z + dz);
    }

    return (a || b || c);
}

int main()
{
    // std::ifstream fin("input.txt");
    // std::ofstream fout("output.txt");

    int n;
    std::cin >> n;
    // fin >> n;

    for (int i = 0; i < n; i++)
    {
        ULL a, b, c;
        std::cin >> a >> b >> c;
        // fin >> a >> b >> c;

        if (solve(a, b, c))
        {
            std::cout << "Yes" << std::endl;
            // fout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
            // fout << "No" << std::endl;
        }
    }

    // fin.close();
    // fout.close();

    return 0;
}
