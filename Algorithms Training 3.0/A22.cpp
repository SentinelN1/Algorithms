#include <iostream>
#include <vector>
#include <stack>

struct elem
{
    int data;
    int length = 1;
    int prev = -1;
};

int main()
{
    int n, ans = 0;
    std::cin >> n;
    std::vector<elem> numbers(n);
    for (int i = 0; i < n; i++)
    {
        int maxLength = 0;
        std::cin >> numbers[i].data;
        for (int j = 0; j < i; j++)
        {
            if (numbers[j].data < numbers[i].data && numbers[j].length > maxLength)
            {
                maxLength = numbers[j].length;
                numbers[i].prev = j;
            }
        }
        numbers[i].length = 1 + maxLength;
        ans = std::max(ans, 1 + maxLength);
    }

    std::stack<int> st;
    int index = n - 1;
    while (index >= 0)
    {
        if (numbers[index].length == ans)
        {
            while (ans > 0)
            {
                // std::cout << numbers[index].data << " ";
                st.push(numbers[index].data);
                index = numbers[index].prev;
                ans--;
            }
            while (!st.empty())
            {
                std::cout << st.top() << " ";
                st.pop();
            }
            return 0;
        }
        index--;
    }
    return 0;
}
