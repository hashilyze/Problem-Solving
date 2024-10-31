// Beakjoon 18310 - 안테나
// https://www.acmicpc.net/problem/18310

#include <algorithm>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
constexpr int MAX_N = 200'000;
// variables
int N;
int arr[MAX_N];

int solution(){
    int left = arr[0], right = arr[N - 1];

    ll sum = 0LL;
    for(int i = 0; i < N; ++i) sum += arr[i] - left;

    ll minSum = sum, minSpot = arr[0];
    for(int i = 1; i < N; ++i){
        int dist = arr[i] - arr[i - 1];
        sum += i * dist;
        sum -= (N - i) * dist;

        if(sum < minSum){
            minSum = sum;
            minSpot = arr[i];
        }
    }
    return minSpot;
}

int main(void){
    FASTIO

    std::cin >> N;
    for(int i = 0; i < N; ++i) std::cin >> arr[i];
    std::sort(arr, arr + N);
    std::cout << solution();

    return 0;
}   