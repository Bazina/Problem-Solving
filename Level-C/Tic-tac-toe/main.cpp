#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pi>
#define all(v)            ((v).begin()), ((v).end())
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define bsrch(a, n)    (binary_search((a).begin(), (a).end(), n))
#define srt(a)     (sort((a).begin(), (a).end()))
#define revsrt(a)     (sort((a).rbegin(), (a).rend()))
#define rev(a)  (reverse((a).begin(), (a).end()))
#define sum(a)      (accumulate((a).begin(), (a).end(), 0ll))
#define cnt(a, i)  (count((a).begin(), (a).end(), i))
#define coutv(a)     for(int i = 0; i < (a).size(); i++) {cout << (a)[i] << " ";}
#define cinv(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i];}
#define cinvP1(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i].first;}
#define cinvP2(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i].second;}
#define isfind(a, s)  a.find(s) != (a).npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b)    for(int (i) = a; (i) < (b); (i)++)


void solve() {
    int winner = 0, cntX = 0, cntO = 0;
    bool winnerX = false, winnerO = false;

    vector<string> board(3);
    cinv(board)

    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (board[i][j] == 'X') cntX++;
            if (board[i][j] == '0') cntO++;
        }
    }

    if (cntX >= cntO + 2 || cntO > cntX) {
        cout << "illegal";
        return;
    }

    for (int i = 0; i <= 2; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.') {
            if (board[i][0] == 'X') winnerX = true;
            else winnerO = true;
        }
    }

    for (int i = 0; i <= 2; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '.') {
            if (board[0][i] == 'X') winnerX = true;
            else winnerO = true;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.') {
        if (board[0][0] == 'X') winnerX = true;
        else winnerO = true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.') {
        if (board[2][0] == 'X') winnerX = true;
        else winnerO = true;
    }

    if (cntX == cntO + 1 && cntX != 5 && cntO != 4) winner = 2;
    else if (cntO == cntX) winner = 1;

    if ((winnerX && winnerO) || (winnerO && cntO + 1 == cntX) || (winnerX && cntX == cntO)) cout << "illegal";
    else if (winnerX) cout << "the first player won";
    else if (winnerO) cout << "the second player won";
    else if (winner == 1) cout << "first";
    else if (winner == 2) cout << "second";
    else cout << "draw";
}

int main() {
    IOS
    solve();
    return 0;
}