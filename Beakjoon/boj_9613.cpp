// Beakjoon 9613번 - GCD 합
// https://www.acmicpc.net/problem/9613

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

// constants
constexpr int MAX_N = 100;
// variables
int arr[MAX_N];

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(void){
    FASTIO
    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        for(int i = 0; i < n; ++i){
            std::cin >> arr[i];
        }

        long long ret = 0LL;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int a = arr[i];
                int b = arr[j];
                if(a < b) std::swap(a, b);
                ret += gcd(arr[i], arr[j]);
            }
        }
        std::cout << ret << '\n';
    }

    return 0;
}