#include <iostream>

using namespace std;

int main() {
    int n, magnet, magnet_temp = 0, group = 0;
    cin >> n;
    if(n == 0){
        group = 0;
    } else {
        group = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            magnet_temp = 0;
        } else {
            magnet_temp = magnet;
        }
        cin >> magnet;
        if (magnet_temp != magnet && i != 0){
            group++;
        }
    }
    cout << group;
    return 0;
}
