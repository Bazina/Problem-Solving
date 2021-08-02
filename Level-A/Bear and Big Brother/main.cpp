#include <iostream>

using namespace std;

int main() {
    int lim, bob, years = 0;
    cin >> lim >> bob;
    while (lim <= bob) {
        lim *= 3;
        bob *= 2;
        years++;
    }
    cout << years;
    return 0;
}
