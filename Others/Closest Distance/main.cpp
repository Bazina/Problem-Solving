#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct point {
    double x;
    double y;
};
int j = 1;
point origin[4];

double dist(point p1, point p2) {
    double distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return distance;
}

void solve() {
    for (auto & i : origin) {
        cin >> i.x;
        cin >> i.y;
    }
    double dist_FT = dist(origin[0], origin[2]), dist_ST = dist(origin[1], origin[3]), eps = 1e-8;
    if ((origin[0].x == origin[2].x && origin[0].y == origin[2].y) ||
        (origin[0].x == origin[3].x && origin[0].y == origin[3].y) ||
        (origin[1].x == origin[3].x && origin[1].y == origin[3].y) ||
        (origin[1].x == origin[2].x && origin[1].y == origin[2].y)) {
        cout << "Case " << j << ": " << 0 << endl;
        j++;
        return;
    }
    while (fabs(dist_FT - dist_ST) > eps) {
        point FTF{}, STF{}, FTS{}, STS{}; // first third first line, second third first line and so on.
        FTF.x = (origin[0].x * 2 + origin[1].x) / 3.0;
        FTF.y = (origin[0].y * 2 + origin[1].y) / 3.0;
        STF.x = (origin[0].x + 2 * origin[1].x) / 3.0;
        STF.y = (origin[0].y + 2 * origin[1].y) / 3.0;
        /* Idea:
         * Line 1: |------||-------||------| we divide it into 3 parts and we do that with the second line.
         * Cal the dist between the first thirds and the dist between the second thirds
         * the bigger one will be the new origin points so we can get the min
        */
        FTS.x = (origin[2].x * 2 + origin[3].x) / 3.0;
        FTS.y = (origin[2].y * 2 + origin[3].y) / 3.0;
        STS.x = (origin[2].x + 2 * origin[3].x) / 3.0;
        STS.y = (origin[2].y + 2 * origin[3].y) / 3.0;

        dist_FT = dist(FTF, FTS), dist_ST = dist(STF, STS);
        if (dist_ST > dist_FT) origin[1] = STF, origin[3] = STS;
        else origin[0] = FTF, origin[2] = FTS;
    }
    cout << "Case " << j << ": " << fixed << setprecision(6) << dist_ST << endl;
    j++;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}