#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int mat[6][6], i , j, moves = 0;
    for (i = 1; i <= 5; ++i) {
        for (j = 1; j <= 5; ++j) {
            cin >> mat[i][j];
            if (mat[i][j] == 1) {
                moves = abs(i - 3) + abs(j - 3);
                cout << "\n" << moves;
                break;
            }
        }
    }
    return 0;
}
