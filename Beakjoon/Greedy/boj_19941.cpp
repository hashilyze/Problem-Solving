// Beakjoon 19941 - 햄버거 분배
// https://www.acmicpc.net/problem/19941

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int MAX_N = 20'000;
// variables
int N, K;
char arr[MAX_N];

int solution(){
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        if(arr[i] != 'P') continue;

        for(int j = std::max(0, i - K); j <= std::min(N - 1, i + K); ++j){
            if(arr[j] == 'H'){
                arr[j] = 'X';
                ++cnt;
                break;
            }
        }
    }
    return cnt;
}

int main(void){
    FASTIO

    std::cin >> N >> K;
    for(int i = 0; i < N; ++i) std::cin >> arr[i];
    std::cout << solution();

    return 0;
}   