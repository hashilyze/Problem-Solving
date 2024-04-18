// Beakjoon 2268번 - 수들의 합 7

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// tpyes
using ll = long long;
// constants
constexpr int MAX_N = 1'000'000 + 10;
// variables
int n, m;
int arr[MAX_N];
ll fenwick[MAX_N];

int getLastBit(int i) { return i & -i; }

void initFenwick(){
    for(int i = 1; i <= n; ++i){
        fenwick[i] = arr[i];

        int j = getLastBit(i);
        int base = i - j;
        j -= 1;
        while(j > 0){
            fenwick[i] = fenwick[base + j];
            j -= getLastBit(j);
        }
    }
}
ll queryFenwick(int pos){
    ll ret = 0LL;
    while(pos > 0) {
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
    std::cin >> n >> m;
    initFenwick();
    while(m--){
        int option, i, j;
        std::cin >> option >> i >> j;
        if(option){ // modify
            updateFenwick(i, (ll)j - arr[i]);
            arr[i] = j;
        } else{ // sum
            if(i > j) std::swap(i, j);
            std::cout << queryFenwick(j) - queryFenwick(i - 1) << '\n';
        }
    }

    return 0;
}