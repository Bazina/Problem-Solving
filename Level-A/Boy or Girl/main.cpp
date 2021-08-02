#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    char name[100];
    cin >> name;
    int counter;
    sort(name, name + strlen(name));
    for (int i = 0; i < strlen(name); ++i) {
        if (name[i] == name[i - 1] && i != 0){
            continue;
        }
        counter++;
    }
    counter % 2 == 0 ? cout << "CHAT WITH HER!" : cout << "IGNORE HIM!";
    return 0;
}
