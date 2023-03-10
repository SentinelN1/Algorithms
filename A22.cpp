#include <iostream>
#include <vector>
#include <stack>

int main()
{
    int n, ans = 0;
    std::cin >> n;
    std::vector<std::vector<int>> numbers(n + 1);
    numbers[0] = std::vector<int>(3);
    numbers[0][1] = 0;  // Length of the longest subsequence
    numbers[0][2] = -1; // Index of previous element in the longest subsequnce
    for (int i = 1; i <= n; i++)
    {
        numbers[i] = std::vector<int>(3);
        std::cin >> numbers[i][0];
        int maxLength = 0;
        for (int j = 1; j < i; j++)
        {
            if (numbers[j][0] < numbers[i][0] && numbers[j][1] > maxLength)
            {
                maxLength = numbers[j][1];
                numbers[i][2] = j;
            }
        }
        numbers[i][1] = 1 + maxLength;
    }

    std::stack<int> st;

    int index = n;
    while (index > 0)
    {
        st.push(numbers[index][0]);
        index = numbers[index][2];
    }

    while (!st.empty())
    {
        std::cout << st.top() << " ";
        st.pop();
    }

    return 0;
}