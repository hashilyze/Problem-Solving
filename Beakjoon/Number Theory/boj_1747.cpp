// Beakjoon 1747 - 소수&팰린드롬
// https://www.acmicpc.net/problem/1747

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
using ll = long long;
// constants
constexpr int SIZE = 1'000'000 * 2;
// variables
bool isPrimes[SIZE + 1];
std::vector<int> primes;


void initPrimes(int n){
    std::memset(isPrimes, true, sizeof(isPrimes));
    for(int i = 2; i <= n; ++i) {
        if(!isPrimes[i]) continue;

        primes.push_back(i);
        for(ll j = (ll)i * i; j <= n; j += i){
            isPrimes[j] = false;
        }
    }
}


int main(void){
    FASTIO
    
    int N; 
    std::cin >> N;
    initPrimes(SIZE);

    auto it = std::lower_bound(primes.begin(), primes.end(), N);
    while(1){
        int p = *it++;
        std::string str = std::to_string(p);
        
        bool isPalindrome = true;
        for(int l = 0, r = str.size() - 1; l <= r; ++l, --r){
            if(str[l] != str[r]) {
                isPalindrome = false;
                break;
            }
        }
        if(isPalindrome){
            std::cout << p;
            break;
        }
    }

    return 0;
}