// Beakjoon 1517번 - 버블 소트(Fenwick)
// https://www.acmicpc.net/problem/1517

#include <iostream>
#include <algorithm>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
constexpr int MAX_N = 500'000 + 10;
// variables
int n;
std::pair<int, int> arr[MAX_N];
ll fenwick[MAX_N];

int getLastBit(int i) { return i & -i; }

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
    for(int i = 0; i < n; ++i) {
        std::cin >> arr[i].first;
        arr[i].second = i;
    }
    std::sort(std::begin(arr), std::end(arr), [](const auto& lhs, const auto& rhs) { return lhs.first > rhs.first; });
    
    ll count = 0LL;
    int prev = 0;
    for(int i = 0; i < n; ++i){
        if(arr[prev].first != arr[i].first){
            for(int j = prev; j < i; ++j){
                updateFenwick(arr[j].second + 1, 1);
            }
            prev = i;
        }
        count += queryFenwick(arr[i].second + 1);
    }
    std::cout << count << '\n';

    return 0;
}