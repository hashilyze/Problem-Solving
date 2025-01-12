// Beakjoon 1990 - 소수인팰린드롬
// https://www.acmicpc.net/problem/1990

#include <cstring>
#include <iostream>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
using ll = long long;
// constants
constexpr int SIZE = 10'000'000;    // 펠린드롬 소수의 자릿수는 항상 홀수
// variables
bool isPrimes[SIZE + 1];


bool isPalindrome(ll n){
    ll l = n;
    ll r = 0LL;
    while(n){
        r = r * 10LL + n % 10LL;
        n /= 10LL;
    }
    return l == r;
}

void init(int n){
    std::memset(isPrimes, true, sizeof(isPrimes));
    for(int i = 2; i * i <= n; ++i) {
        if(!isPrimes[i]) continue;
        for(ll j = (ll)i * i; j <= n; j += i){
            isPrimes[j] = false;
        }
    }
}


int main(void){
    FASTIO
    init(SIZE);

    int a, b; 
    std::cin >> a >> b;
    for(int i = a; i <= b && i < SIZE; ++i){
        if(isPrimes[i] && isPalindrome(i)) std::cout << i << '\n';
    }
    std::cout << -1;

    return 0;
}