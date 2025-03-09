// https://leetcode.cn/problems/count-of-smaller-numbers-after-self/description/

/*
计算右侧小于当前元素的数
给你一个整数数组 nums ，按要求返回一个新数组 counts 。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> counts;
    vector<pair<int, int>> with_idx;
    void merge(vector<pair<int, int>>::iterator aBegin,
               vector<pair<int, int>>::iterator aEnd,
               vector<pair<int, int>>::iterator bBegin,
               vector<pair<int, int>>::iterator bEnd,
               vector<pair<int, int>>::iterator c) {
        auto mid = bBegin;
        while (aBegin != aEnd && bBegin != bEnd) {
            if (aBegin->first <= bBegin->first) {
                counts[aBegin->second] += bBegin - mid;
                *(c++) = *(aBegin++);

            } else {
                // counts[(*bBegin).second] += mid - aBegin;
                *(c++) = *(bBegin++);
            }
        }
        while (aBegin != aEnd) {
            counts[aBegin->second] += bBegin - mid;
            *(c++) = *(aBegin++);
        }
        while (bBegin != bEnd) {
            // counts[(*bBegin).second] += mid - aBegin;
            *(c++) = *(bBegin++);
        }
    }

    vector<int> countSmaller(vector<int> &nums) {
        int idx = 0;
        int n = nums.size();
        for (auto &&i : nums) with_idx.push_back({i, idx++});

        vector<pair<int, int>> tmp(n);
        counts.assign(n, 0);
        auto a0 = with_idx.begin();
        auto tmp0 = tmp.begin();
        for (int seg = 1; seg < n; seg *= 2) {
            for (int l = 0; l < n - seg; l += seg * 2) {
                int m = l + seg, r = m + seg;
                merge(a0 + l, a0 + m, a0 + m, min(a0 + r, with_idx.end()),
                      tmp0 + l);
                copy(tmp0 + l, min(tmp0 + r, tmp.end()), a0 + l);
            }
        }
        return counts;
    }
};

int main() {
    Solution solve;
    vector<int> q = {0,1,2};
    vector<int> ans = solve.countSmaller(q);
    for (auto &&i : ans) {
        cout << i << ' ';
    }
}