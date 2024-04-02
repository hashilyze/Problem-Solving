// Beakjoon 1275번 - 커피숍2

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
//types
using ll = long long;
// constants
constexpr int MAX_N = 100'000 + 10;
// variables
int n, q;
int arr[MAX_N];
ll fenwick[MAX_N];

int getLastBit(int n) { return n & -n; }

void initFenwick(){
    for(int i = 1; i <= n; ++i){
        fenwick[i] = arr[i];

        int j = getLastBit(i);
        int base = i - j;
        j -= 1;
        while(j > 0){
            fenwick[i] += fenwick[base + j];
            j -= getLastBit(j);
        }
    }
}
ll queryFenwick(int pos){
    ll ret = 0LL;
    while(pos > 0){
        ret += fenwick[pos];
        pos -= getLastBit(pos);
    }
    return ret;
}
void updateFenwick(int pos, ll diff){
    while(pos <= n){
        fenwick[pos] += diff;
        pos += getLastBit(pos);
    }
}

int main(void){
    FASTIO

    std::cin >> n >> q;
    for(int i = 1; i <= n; ++i) std::cin >> arr[i];
    initFenwick();
    while(q--){
        int x, y, a;
        ll b;
        std::cin >> x >> y >> a >> b;
        if(x > y) std::swap(x, y);
        std::cout << queryFenwick(y) - queryFenwick(x - 1) << "\n";
        updateFenwick(a, b - arr[a]);
        arr[a] = b;
    }

    return 0;
}