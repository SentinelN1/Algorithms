#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef unsigned long long int ULLI;

int main()
{
	map<char, ULLI> count1;
    map<char, ULLI> count2;

	string num1, num2;
    cin >> num1 >> num2;
    ULLI n1 = num1.length();
    ULLI n2 = num2.length();
    ULLI N;
    if (n1 == n2)
    {
    	N = n1;
    }
	
    ULLI cows = 0;
	ULLI bulls = 0;

	for (ULLI i = 0; i < N; i++)
    {
    	char c1 = num1[i];
        char c2 = num2[i];
        
        if (c1 == c2)
        {
        	bulls++;
        } else {
        	count1[c1]++;
        	count2[c2]++;
		}
    }
    
    for (char c = '0'; c <= '9'; c++)
    {
    	cows += min(count1[c], count2[c]);
    }
    cout << bulls << '\n' << cows;
}