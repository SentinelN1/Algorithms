#include <iostream>
#include <vector>

typedef unsigned long long int ULLI;

int main() {
    ULLI n, m;
    std::cin >> n >> m;
    std::vector<ULLI> matrix(n * m);

    for (ULLI i = 0; i < n * m; i++) {
        std::cin >> matrix[i];
    }

    for (ULLI i = 0; i < n; i++) {
        for (ULLI j = 0; j < m; j++)
        {
            std::cout << matrix[i * m + j] << " ";
        }
        std::cout << "\n";
    }

    
}