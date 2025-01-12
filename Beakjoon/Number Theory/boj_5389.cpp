// Beakjoon 5389 - 제곱근 작도
// https://www.acmicpc.net/problem/5389

#include <climits>
#include <iostream>
#include <tuple>
#include <utility>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
using pii = std::pair<int, int>;
// constants
// variables

pii solution(int n){
    // n + l^2 = r^2
    // n = r^2 - l^2 = (r + l)*(r - l) = a*b

    int minR = INT_MAX, minL = INT_MAX;
    for(int k = 1; k * k <= n; ++k){
        if(n % k == 0) {
            int a = k;
            int b = n / k;

            if((a + b) % 2 == 0 && (a - b) % 2 == 0){
                int r = (b + a) / 2;
                int l = (b - a) / 2;

                if(minR > r){
                    minR = r;
                    minL = l;
                }
            }
        }
    }
    return {minR, minL};
}

int main(void){
    FASTIO
    
    int T;
    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        
        int r, l;
        std::tie(r, l) = solution(n);
        if(r == INT_MAX && l == INT_MAX)
            std::cout << "IMPOSSIBLE" << '\n';
        else 
            std::cout << l << ' ' << r << '\n';
    }
    
    

    return 0;
}