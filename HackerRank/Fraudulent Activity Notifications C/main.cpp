#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define srt(a)     (sort((a).begin(), (a).end()))
#define revsrt(a)     (sort((a).rbegin(), (a).rend()))
#define rev(a)  (reverse((a).begin(), (a).end()))
#define coutv(a)     for(int i = 0; i < (a).size(); i++) {cout << (a)[i] << " ";}
#define cinv(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i];}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll MAXN = 1e6 + 5, mod = 1e9 + 7;

class Solution {
public:
    multiset<double> leftSet, rightSet;
    int idx = 0;

    void reBalance() {
        if (rightSet.size() > leftSet.size() + 1) {
            double remove = *rightSet.begin();
            rightSet.erase(rightSet.begin());
            leftSet.insert(remove);
        } else if (leftSet.size() > rightSet.size() + 1) {
            double remove = *(--leftSet.end());
            leftSet.erase(--leftSet.end());
            rightSet.insert(remove);
        }
    }


    void addNum(int num) {
        if (!rightSet.empty() && num > *rightSet.begin())
            rightSet.insert(num);
        else {
            leftSet.insert(num);
        }

        reBalance();

        idx++;
    }

    void remove(int num) {
        auto itr = leftSet.find(num);
        if (!leftSet.empty() && itr != leftSet.end())
            leftSet.erase(itr);
        else
            rightSet.erase(rightSet.find(num));

        reBalance();
    }

    double findMedian(int d) {
        if (d % 2 == 0)
            return (*--leftSet.end() + *rightSet.begin()) / 2.0;

        return leftSet.size() > rightSet.size() ? *--leftSet.end() : *rightSet.begin();
    }

    int activityNotifications(vector<int> expenditure, int d) {
        double median;
        int notificationCount = 0;
        for (int i = 0; i < expenditure.size() - 1; i++) {
            addNum(expenditure[i]);
            if (i - d + 1 >= 0) {
                median = findMedian(d);
                if (median * 2 <= expenditure[i + 1])
                    notificationCount++;

                remove(expenditure[i - d + 1]);
            }
        }

        return notificationCount;
    }
};

int main() {
    IOS
    vector<int> nums{2, 3, 4, 2, 3, 6, 8, 4, 5};
    int k = 5;
    Solution solution;
    cout << solution.activityNotifications(nums, k) << '\n';

    return 0;
}