// Beakjoon 1517번 - 버블 소트(Mergesort)
// https://www.acmicpc.net/problem/1517

#include <iostream>
#include <cstring>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
constexpr int MAX_N = 500'000 + 10;
// variables
int n;
int arr[MAX_N];
int tmp[MAX_N];

ll mergeSort(int left, int right){
    if(left == right) return 0LL;
    
    ll cnt = 0;
    int mid = (left + right) >> 1;
    cnt += mergeSort(left, mid);
    cnt += mergeSort(mid + 1, right);

    int cur = left, lcur = left, rcur = mid + 1;
    while(lcur <= mid && rcur <= right){
        if(arr[lcur] <= arr[rcur]) {
            tmp[cur++] = arr[lcur++];
        } else {
            cnt += mid - lcur + 1;
            tmp[cur++] = arr[rcur++];
        }
    }
    while(lcur <= mid) tmp[cur++] = arr[lcur++];
    while(rcur <= right) tmp[cur++] = arr[rcur++];
    std::memcpy(arr + left, tmp + left, sizeof(int) * (right - left + 1));

    return cnt;
}

int main(void){
    FASTIO
    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> arr[i];
    
    ll count = mergeSort(0, n - 1);
    std::cout << count << '\n';

    return 0;
}