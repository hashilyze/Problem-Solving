// Beakjoon 11005 - 진법 변환 2
// https://www.acmicpc.net/problem/11005

#include <bits/stdc++.h>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
// variables
int N, B;


// 10진법 숫자 i를, N진법 숫자로 변환
inline char convert(int i) { 
    if(i < 10) return '0' + i;
    else return 'A' + (i - 10);
}

int main(void){
    FASTIO

    std::cin >> N >> B;
    std::string ans = "";
    
    while(N > 0){
        ans += convert(N % B);
        N /= B;
    }
    std::reverse(ans.begin(), ans.end());

    std::cout << ans;

    return 0;
}