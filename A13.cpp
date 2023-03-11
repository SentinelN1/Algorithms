#include <iostream>
#include <stack>
#include <queue>
#include <map>

int main()
{
    std::map<char, int> priority = {{'!', 3}, {'&', 2}, {'|', 1}, {'^', 1}};
    std::string str;
    std::getline(std::cin, str);
    std::stack<char> stack;
    std::queue<char> result;
    for (char cur : str)
    {
        if (cur == '0' || cur == '1')
        {
            result.push(cur);
            // std::cout << cur << " added to result\n";
            continue;
        }
        if (cur == '(' || cur == ')' || cur == '!')
        {
            stack.push(cur);
            // std::cout << cur << " added to stack\n";
            continue;
        }
        if (!stack.empty())
        {
            char top = stack.top();
            if (top == ')')
            {
                while (top != '(')
                {
                    if (top != '(' && top != ')')
                    {
                        result.push(top);
                        // std::cout << top << " added to result\n";
                    }
                    stack.pop();
                    // std::cout << top << " removed from stack\n";
                    top = stack.top();
                }

                stack.pop();
                // std::cout << top << " removed from stack\n";
                if (!stack.empty())
                {
                    top = stack.top();
                }
            }
            else
            {
                while (top != '(' && priority[top] >= priority[cur] && !stack.empty())
                {
                    result.push(top);
                    // std::cout << top << " added to result\n";

                    stack.pop();
                    // std::cout << top << " removed from stack\n";

                    if (!stack.empty())
                    {
                        top = stack.top();
                    }
                }
            }
        }

        stack.push(cur);
        // std::cout << cur << " added to stack\n";
    }

    while (!stack.empty())
    {
        char top = stack.top();
        if (top != '(' && top != ')')
        {
            result.push(top);
        }
        stack.pop();
    }
    // std::cout << "\n";

    while (!result.empty())
    {
        char cur = result.front();
        // std::cout << cur;
        result.pop();

        if (cur == '0' || cur == '1')
        {
            stack.push(cur);
            // std::cout << cur << " added to stack\n";
            continue;
        }

        if (cur == '!')
        {
            char val = stack.top();
            stack.pop();
            // std::cout << val << " removed from stack; ";
            if (val == '1')
            {
                stack.push('0');
                // std::cout << "0 added to stack\n";
                continue;
            }
            stack.push('1');
            // std::cout << "1 added to stack\n";
            continue;
        }

        if (cur == '&')
        {
            char rval = stack.top();
            stack.pop();

            char lval = stack.top();
            stack.pop();
            // std::cout << rval << ", " << lval << " removed from stack; ";

            if (rval == '1' && lval == '1')
            {
                stack.push('1');
                // std::cout << "1 added to stack\n";
                continue;
            }
            // std::cout << "0 added to stack\n";
            stack.push('0');
            continue;
        }

        if (cur == '|')
        {
            char rval = stack.top();
            stack.pop();

            char lval = stack.top();
            stack.pop();

            if (rval == '1' || lval == '1')
            {
                stack.push('1');
                // std::cout << "1 added to stack\n";
                continue;
            }
            stack.push('0');
            // std::cout << "0 added to stack\n";
            continue;
        }

        if (cur == '^')
        {
            char rval = stack.top();
            stack.pop();
            char lval = stack.top();
            stack.pop();
            // std::cout << rval << ", " << lval << " removed from stack; ";
            if (rval == lval)
            {
                stack.push('0');
                // std::cout << "0 added to stack\n";
                continue;
            }
            stack.push('1');
            // std::cout << "1 added to stack\n";
            continue;
        }
    }
    std::cout << stack.top();
}
