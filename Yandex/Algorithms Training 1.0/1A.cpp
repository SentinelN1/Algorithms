#include <iostream>

using namespace std;

int main()
{
    int tRoom, tCond;
    string mode;
    cin >> tRoom >> tCond >> mode;
    if (mode == "auto" || mode == "heat" && tRoom < tCond || mode == "freeze" && tRoom > tCond) {
        cout << tCond;
        return 0;
    } else {
        cout << tRoom;
        return 0;
    }
}
