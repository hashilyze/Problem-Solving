// Beakjoon 32291 - x와 x+1의 차이
// https://www.acmicpc.net/problem/32291

#include <algorithm>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
using ll = long long;
// constants
// variables


int main(void){
    FASTIO
    
    ll x;
    std::cin >> x;

    std::vector<ll> divisors = { 1, };
    for(ll k = 2, n = x + 1; k * k <= n; ++k){
        if(n % k == 0) {
            divisors.push_back(k);
            if(k * k != n) divisors.push_back(n / k);
        }
    }
    std::sort(divisors.begin(), divisors.end());
    for(ll d : divisors) std::cout << d << ' ';
    

    return 0;
}