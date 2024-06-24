#include <iostream>

using namespace std;

int Solve(int num)
{
	if (num == 0)
    {
    	return 0;
    }
    
    if (num % 2 == 0)
    {
    	return 1 + Solve(num / 2);
    }
    else
    {
    	return 1 + Solve(num - 1);
    }
}


int main()
{
	int n;
    cin >> n;
    int res = Solve(n);
    cout << res;
}