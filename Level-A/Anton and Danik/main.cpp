#include <iostream>
using namespace std;

int main() {
    int A = 0, D = 0, n;
    char win;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> win;
        if (win == 'A'){
            ++A;
        } else if (win == 'D'){
            ++D;
        }
    }
    if (A > D){
        cout << "Anton";
    } else if (A < D){
        cout << "Danik";
    } else if (A == D){
        cout << "Friendship";
    }
    return 0;
}
