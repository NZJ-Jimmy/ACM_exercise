#include <bits/stdc++.h>
using namespace std;

// 对有序数组归并
vector<int> merge(const vector<int> &a, const vector<int> &b) {
  auto i = a.begin(), j = b.begin();
  vector<int> ans;
  while (i != a.end() && j != b.end()) {
    if (*i <= *j)
      ans.push_back(*(i++));
    else
      ans.push_back(*(j++));
  }
  while (i != a.end()) ans.push_back(*(i++));
  while (j != b.end()) ans.push_back(*(j++));
  return ans;
}

vector<int> mergeSort(vector<int>::iterator begin, vector<int>::iterator end) {
  if (end - begin == 1) return {*begin};
  vector<int>::iterator mid = begin + (end - begin) / 2;
  auto seq1 = mergeSort(begin, mid);
  auto seq2 = mergeSort(mid, end);
  return merge(seq1, seq2);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto result = mergeSort(a.begin(), a.end());

  for (auto &&i : result) {
    cout << i << " ";
  }

  return 0;
}