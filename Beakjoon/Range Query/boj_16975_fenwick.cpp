// Beakjoon 16975번 - 수열과 쿼리 21

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// type
using ll = long long;
//constants
constexpr int MAX_N = 100'000 + 10;
// variables
int n, m;
ll fenwick[MAX_N];
// functions
int getLastBit(int i) { return i & -i; }

void initFenwick(){
    for(int i = 1; i <= n; ++i){
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
void updateFenwick(int pos, int diff){
    while(pos <= n){
        fenwick[pos] += diff;
        pos += getLastBit(pos);
    }
}

int main(void){
    FASTIO
    std::cin >> n;
    int prev = 0;
    for(int i = 0; i < n; ++i) {
        int input;
        std::cin >> input;
        fenwick[i + 1] = input - prev;
        prev = input;
    }
    initFenwick();

    std::cin >> m;
    while(m--){
        int option;
        std::cin >> option;
        switch(option){
        case 1:{
            int i, j;
            ll k;
            std::cin >> i >> j >> k;
            updateFenwick(i, k);
            updateFenwick(j + 1, -k);
        } break;
        case 2:{
            int x;
            std::cin >> x;
            std::cout << queryFenwick(x) << '\n';
        } break;
        }
    }

    return 0;
}