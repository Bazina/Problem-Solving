#include <stdio.h>

int main() {
    int A = 0, D = 0, n;
    char win;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf(" %c", &win);
        if (win == 'A'){
            ++A;
        } else if (win == 'D'){
            ++D;
        }
    }
    if (A > D){
        printf("Anton");
    } else if (A < D){
        printf("Danik");
    } else if (A == D){
        printf("Friendship");
    }
    return 0;
}
