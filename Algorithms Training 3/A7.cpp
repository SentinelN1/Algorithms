#include <iostream>

int main()
{
    std::string strArray[3];
    std::cin >> strArray[0] >> strArray[1] >> strArray[2];
    int timeArray[3];
    for (size_t i = 0; i < 3; i++)
    {
        int h1 = int(strArray[i][0] - '0');
        int h2 = strArray[i][1] - '0';
        int h = 10 * h1 + h2;

        int m1 = strArray[i][3] - '0';
        int m2 = strArray[i][4] - '0';
        int m = 10 * m1 + m2;

        int s1 = strArray[i][6] - '0';
        int s2 = strArray[i][7] - '0';
        int s = 10 * s1 + s2;

        timeArray[i] = 3600 * h + 60 * m + s;
    }

    int twoPeriod = timeArray[2] - timeArray[0];
    if (twoPeriod < 0)
    {
        twoPeriod += 24 * 60 * 60;
    }
    int result = timeArray[1] + twoPeriod / 2;
    if (twoPeriod % 2 == 1)
    {
        result++;
    }
    int s = result % 60;
    int m = (result / 60) % 60;
    int h = (result / 3600) % 24;
    if (h < 10)
    {
        std::cout << "0";
    }
    std::cout << h << ":";
    if (m < 10)
    {
        std::cout << "0";
    }
    std::cout << m << ":";
    if (s < 10)
    {
        std::cout << "0";
    }
    std::cout << s;
}
