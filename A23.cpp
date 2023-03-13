// Количество треугольников
#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<long long int> vec(n + 1);
    vec[1] = 1;
    for (long long int i = 2; i <= n; i++)
    {
        vec[i] = vec[i - 1] + i * (i + 1) / 2 + (i / 2) * (i - i / 2);
    }
    std::cout << vec[n];
}
