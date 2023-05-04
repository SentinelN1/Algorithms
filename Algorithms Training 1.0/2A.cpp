#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    while (fin)
    {
        int tmp;
        fin >> tmp;
        cout << tmp << ' ';
    }
}
