#include <iostream>
#include <vector>
#include <string>

int main()
{
    int n, m;
    std::cin >> n;
    std::vector<char> seats(7 * n);
    for (int i = 0; i < 7 * n; ++i)
    {
        std::cin >> seats[i];
    }

    std::cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int num;
        std::string side, pos;
        std::cin >> num >> side >> pos;

        // LEFT
        if (side == "left")
        {
            // LEFT WINDOW
            if (pos == "window")
            {
                bool available = false;
                for (int i = 0; i < n; i++)
                {
                    bool cur = true;
                    for (int j = 0; j < num; j++)
                    {
                        if (seats[7 * i + j] != '.')
                        {
                            cur = false;
                            break;
                        }
                    }
                    if (cur)
                    {
                        available = true;
                        std::cout << "Passengers can take seats:";
                        std::cout << " " << i + 1 << "A";
                        if (num > 1)
                        {
                            std::cout << " " << i + 1 << "B";
                        }
                        if (num > 2)
                        {
                            std::cout << " " << i + 1 << "C";
                        }
                        std::cout << "\n";

                        for (int row = 0; row < n; ++row)
                        {
                            for (int j = 0; j < 7; j++)
                            {
                                if (row == i && j >= 0 && j < num)
                                {
                                    std::cout << "X";
                                    seats[7 * row + j] = '#';
                                }
                                else
                                {
                                    std::cout << seats[7 * row + j];
                                }
                            }
                            std::cout << "\n";
                        }
                        break;
                    }
                }
                if (!available)
                {
                    std::cout << "Cannot fulfill passengers requirements\n";
                }
            }
            // LEFT AISLE
            else
            {
                bool available = false;
                for (int i = 0; i < n; i++)
                {
                    bool cur = true;
                    for (int j = 2; j >= 3 - num; --j)
                    {
                        if (seats[7 * i + j] != '.')
                        {
                            cur = false;
                            break;
                        }
                    }
                    if (cur)
                    {
                        available = true;
                        std::cout << "Passengers can take seats:";
                        if (num > 2)
                        {
                            std::cout << " " << i + 1 << "A";
                        }
                        if (num > 1)
                        {
                            std::cout << " " << i + 1 << "B";
                        }
                        std::cout << " " << i + 1 << "C\n";

                        for (int row = 0; row < n; ++row)
                        {
                            for (int j = 0; j < 7; ++j)
                            {
                                if (row == i && j >= 3 - num && j <= 2)
                                {
                                    seats[7 * row + j] = '#';
                                    std::cout << 'X';
                                }
                                else
                                {
                                    std::cout << seats[7 * row + j];
                                }
                            }
                            std::cout << '\n';
                        }
                        break;
                    }
                }
                if (!available)
                {
                    std::cout << "Cannot fulfill passengers requirements\n";
                }
            }
        }
        // RIGHT
        else
        {
            // RIGHT WINDOW
            if (pos == "window")
            {
                bool available = false;
                for (int i = 0; i < n; i++)
                {
                    bool cur = true;
                    for (int j = 6; j >= 7 - num; --j)
                    {
                        if (seats[7 * i + j] != '.')
                        {
                            cur = false;
                            break;
                        }
                    }
                    if (cur)
                    {
                        available = true;

                        std::cout << "Passengers can take seats:";
                        if (num > 2)
                        {
                            std::cout << " " << i + 1 << "D";
                        }
                        if (num > 1)
                        {
                            std::cout << " " << i + 1 << "E";
                        }
                        std::cout << " " << i + 1 << "F\n";

                        for (int row = 0; row < n; ++row)
                        {
                            for (int j = 0; j < 7; j++)
                            {
                                if (row == i && j >= 7 - num && j <= 6)
                                {
                                    std::cout << "X";
                                    seats[7 * row + j] = '#';
                                }
                                else
                                {
                                    std::cout << seats[7 * row + j];
                                }
                            }
                            std::cout << "\n";
                        }
                        break;
                    }
                }
                if (!available)
                {
                    std::cout << "Cannot fulfill passengers requirements\n";
                }
            }
            // RIGHT SIDE AISLE
            else
            {
                bool available = false;
                for (int i = 0; i < n; i++)
                {
                    bool cur = true;
                    for (int j = 4; j < 4 + num; j++)
                    {
                        if (seats[7 * i + j] != '.')
                        {
                            cur = false;
                            break;
                        }
                    }
                    if (cur)
                    {
                        available = true;
                        std::cout << "Passengers can take seats:";
                        std::cout << " " << i + 1 << "D";
                        if (num > 1)
                        {
                            std::cout << " " << i + 1 << "E";
                        }
                        if (num > 2)
                        {
                            std::cout << " " << i + 1 << "F";
                        }
                        std::cout << "\n";
                        for (int row = 0; row < n; ++row)
                        {
                            for (int j = 0; j < 7; j++)
                            {
                                if (row == i && j >= 4 && j < 4 + num)
                                {
                                    std::cout << "X";
                                    seats[7 * row + j] = '#';
                                }
                                else
                                {
                                    std::cout << seats[7 * row + j];
                                }
                            }
                            std::cout << "\n";
                        }
                        break;
                    }
                }
                if (!available)
                {
                    std::cout << "Cannot fulfill passengers requirements\n";
                }
            }
        }
    }
}
