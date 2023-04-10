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

    double findMedian(int k) {
        if (k % 2 == 0)
            return (*--leftSet.end() + *rightSet.begin()) / 2.0;

        return leftSet.size() > rightSet.size() ? *--leftSet.end() : *rightSet.begin();
    }

    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        vector<double> result(nums.size() - k + 1);
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            addNum(nums[i]);
            if (i - k + 1 >= 0) {
                result[j++] = findMedian(k);
                remove(nums[i - k + 1]);
            }
        }

        return result;
    }
};

int main() {
    IOS
    vector<int> nums{2147483647,2147483647};
    int k = 2;
    Solution solution;
    vector<double> z = solution.medianSlidingWindow(nums, k);
    for (int i = 0; i < z.size(); ++i) {
        cout << z[i] << '\n';
    }
    return 0;
}