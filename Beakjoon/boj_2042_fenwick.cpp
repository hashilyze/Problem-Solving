// Beakjoon 2042번 - 구간 합 구하기 (Fenwick)

#include <iostream>

void setFastIO(){
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

// type
using BigInt = long long;
// const
constexpr BigInt MAX_N = 1'000'000 + 10;
// variable
BigInt arr[MAX_N] = { 0, };
BigInt fenwick[MAX_N] = { 0, };
int n, m, k;
// function

int lastBit(int i) { return i & -i; }

void initFenwick(){
    for(int i = 1; i <= n; ++i){
        fenwick[i] = arr[i];
        int base = i - lastBit(i);
        int j = i - base - 1;
        while(j > 0){
            fenwick[i] += fenwick[base + j];
            j -= lastBit(j);
        }
    }
}
BigInt queryFenwick(int index){
    BigInt ret = 0LL;
    while(index){
        ret += fenwick[index];
        index -= lastBit(index);
    }
    return ret;
}
void updateFenwick(int index, BigInt val){
    BigInt diff = val - arr[index];
    arr[index] = val;
    while(index <= n){
        fenwick[index] += diff;
        index += lastBit(index);
    }
}

void logFenwick(){
    for(int i = 0; i <= n; ++i){
        std::cout << fenwick[i] << ", ";
    }
    std::cout << '\n';
}


int main(void){
    setFastIO();
    std::cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i) std::cin >> arr[i];
    initFenwick();

    for(int i = 0, e = m + k; i < e; ++i){
        int a, b;
        BigInt c;
        std::cin >> a >> b >> c;
        switch(a){ // update
        case 1:{
            updateFenwick(b, c);
        } break;
        case 2:{ // sub sum
            std::cout << queryFenwick((int)c) - queryFenwick(b-1) << '\n';
        } break;
        }
    }

    return 0;
}