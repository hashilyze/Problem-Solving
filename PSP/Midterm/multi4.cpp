#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// #define ONLINE_JUDGE

// === File Control ====
const std::string FILE_NAME = "multi4";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";
// types
using ll = long long;
// constants
constexpr int MAX_N = 10000 + 100;
// variables
int n, m;
ll arr[MAX_N];
int pos, neg, zero;

ll solveMin(){
    ll min = arr[0] * arr[1] * arr[2] * arr[3];
    if(neg == 0){ // 0 이상의 정수로 구성
        // min = std::min(min, arr[0] * arr[1] * arr[2] * arr[3]);
    } else if(pos == 0){ // 0이하의 정수로 구성
        min = std::min(min, arr[n - 4] * arr[n - 3] * arr[n - 2] * arr[n - 1]);
    } else{ // 양수, 음수가 한 개 이상 포함
        if(zero > 0) // 0을 포함
            min = std::min(min, 0LL);
        if(pos >= 3 && neg >= 1)
            min = std::min(min, arr[0] * arr[n - 3] * arr[n - 2] * arr[n - 1]);
        if(pos >= 1 && neg >= 3)
            min = std::min(min, arr[0] * arr[1] * arr[2] * arr[n - 1]);
    }
    return min;
}
ll solveMax(){
    ll max = arr[n - 1] * arr[n - 2] * arr[n - 3] * arr[n - 4];
    if(neg == 0){ // 0 이상의 정수로 구성
        //max = std::max(max, arr[n - 1] * arr[n - 2] * arr[n - 3] * arr[n - 4]);
    } else if(pos == 0){ // 0이하의 정수로 구성
        max = std::max(max, arr[0] * arr[1] * arr[2] * arr[3]);
    } else{ // 양수, 음수가 한 개이상 포함됨
        if(zero > 0) // 0을 포함
            max = std::max(max, 0LL);

        if(pos >= 2 && neg >= 2) 
            max = std::max(max, arr[0] * arr[1] * arr[n - 2] * arr[n - 1]);
        if(pos >= 4)
            max = std::max(max, arr[n - 4] * arr[n - 3] * arr[n - 2] * arr[n - 1]);
        if(neg >= 4)
            max = std::max(max, arr[0] * arr[1] * arr[2] * arr[3]);
    }
    return max;
}

void countSign(){
    neg = pos = zero = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] < 0) ++neg;
        else if(arr[i] > 0) ++pos;
        else ++zero;
    }
}

int main(void){
#ifndef ONLINE_JUDGE
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);
    std::istream& in = fin;
    std::ostream& out = fout;
#else
    std::istream& in = std::cin;
    std::ostream& out = std::cout;
#endif
    int t;
    in >> t;
    
    while(t--){
        in >> n;
        for(int i = 0; i < n; ++i) in >> arr[i];
        std::sort(arr, arr + n);
        countSign();
        out << solveMin() << " " << solveMax() << '\n';
    }
#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}