#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

void merge(int *aBegin, int *aEnd, int *bBegin, int *bEnd, int *c) {
    while (aBegin < aEnd && bBegin < bEnd) {
        if (*aBegin <= *bBegin)
            *(c++) = *(aBegin++);
        else
            *(c++) = *(bBegin++);
    }
    while (aBegin < aEnd) *(c++) = *(aBegin++);
    while (bBegin < bEnd) *(c++) = *(bBegin++);
}

void mergeSort(int *begin, int *end, int *tmp, int begin_idx = 0) {
    if (end - begin == 1) {
        tmp[begin_idx] = *begin;
    } else {
        int *mid = begin + (end - begin) / 2;
        mergeSort(begin, mid, tmp, begin_idx);
        mergeSort(mid, end, tmp, begin_idx + (mid - begin));
        merge(begin, mid, mid, end, tmp + begin_idx);
    }
    while (begin < end) *(begin++) = *(tmp++ + begin_idx);
}

int main() {
    int n;
    cin >> n;
    int a[n], result[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mergeSort(a, a + n, result);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}