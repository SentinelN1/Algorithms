#include <iostream>
#include <vector>
#include <stack>

std::vector<int> results;
std::stack<int> path;

int Calculator(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    int t1, t2, t3;
    t1 = results[n - 1];
    if (t1 == -1)
    {
        t1 = Calculator(n - 1);
        results[n - 1] = t1;
    }
    if (n % 2 == 0)
    {
        t2 = results[n / 2];
        if (t2 == -1)
        {
            t2 = Calculator(n / 2);
            results[n / 2] = t2;
        }
        t1 = std::min(t1, t2);
    }
    if (n % 3 == 0)
    {
        t3 = results[n / 3];
        if (t3 == -1)
        {
            t3 = Calculator(n / 3);
            results[n / 3] = t3;
        }
        t1 = std::min(t1, t3);
    }
    return 1 + t1;
}

void Path(int n)
{
    if (n <= 1)
    {
        path.push(1);
        return;
    }
    path.push(n);

    int t1, t2, t3;
    int i;
    t1 = results[n - 1];
    i = n - 1;
    if (n % 2 == 0)
    {
        t2 = results[n / 2];
        if (t2 < t1)
        {
            t1 = t2;
            i = n / 2;
        }
    }
    if (n % 3 == 0)
    {
        t3 = results[n / 3];
        if (t3 < t1)
        {
            t1 = t3;
            i = n / 3;
        }
    }
    Path(i);
}

int main()
{
    int n;
    std::cin >> n;
    results = std::vector<int>(n);
    for (auto &i : results)
    {
        i = -1;
    }
    int c = Calculator(n);
    std::cout << c << std::endl;
    Path(n);

    while (!path.empty())
    {
        std::cout << path.top() << " ";
        path.pop();
    }

    return 0;
}