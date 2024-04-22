#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
constexpr int MAX_N = 10;
// variabels
ll fact[MAX_N + 1];
ll dp[MAX_N + 1][MAX_N + 1];

void initFact(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < MAX_N; ++i){
        fact[i] = fact[i - 1] * i;
    }
}

ll comb(int n, int k){
    ll a = fact[n];
    ll b = fact[k] * fact[n - k];
    return a / b;
}

ll R(ll n, ll k){
    ll &r = dp[n][k];
    if(r > 0) return r;

    if(n == k) return r = 1LL;
    if(k == 1) return r = fact[n - 1];

    r = 0LL;
    for(int i = k; i <= n; ++i){
        r += comb(n - 1, i - 1) * R(i - 1, k - 1) * fact[n - i];
    }
    return r;
}

int main(void){
    FASTIO
    
    initFact();
    int t;
    std::cin >> t;

    while(t--){
        int n, k;
        std::cin >> n >> k;
        std::cout << R(n, k) << '\n';
    }

    return 0;
}