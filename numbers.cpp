#include <iostream>
#include <map>
std::map<int, int> numbers;

int evaluate(int n, int k)
{
    if (n == k)
    {
        numbers[k] = 0;
        return 0;
    }

    int result;

    int leftNum = n / 10 + n % 10 * 1000;
    int leftVal = numbers[leftNum];
    if (leftVal == -1)
    {
        leftVal = evaluate(leftNum, k);
        numbers[leftNum] = leftVal;
    }

    int rightNum = (n * 10 + n / 1000) % 10000;
    int rightVal = numbers[rightNum];
    if (rightVal == -1)
    {
        rightVal = evaluate(rightNum, k);
        numbers[rightNum] = rightVal;
    }
    result = std::min(leftVal, rightVal);

    if (n / 1000 != 9)
    {
        int val = numbers[n + 1000];
        if (val == -1)
        {
            val = evaluate(1000 + n, k);
            numbers[1000 + n] = val;
        }
        result = std::min(result, val);
    }

    if (n % 10 != 1)
    {
        int val = numbers[n - 1];
        if (val == -1)
        {
            val = evaluate(n - 1, k);
            numbers[n - 1] = val;
        }
        result = std::min(result, val);
    }
    return 1 + result;
}

int main()
{
    int fromNumber, toNumber;
    std::cin >> fromNumber >> toNumber;
    for (size_t i = 0; i < 10000; i++)
    {
        numbers[i] = -1;
    }

    std::cout << evaluate(fromNumber, toNumber);
}