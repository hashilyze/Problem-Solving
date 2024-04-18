// Beakjoon 29197번 - 아침 태권도
// https://www.acmicpc.net/problem/29197

#include <iostream>
#include <set>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


int main(void){
    FASTIO

    int n;
    std::cin >> n;

    std::set<std::pair<int, int>> hash;
    while(n--){
        int x, y, absX, absY;
        std::cin >> x >> y;
        absX = std::abs(x); absY = std::abs(y);

        int d = (absX >= absY ? gcd(absX, absY) : gcd(absY, absX));
        hash.insert({y / d, x / d});
    }
    std::cout << hash.size() << '\n';

    return 0;
}