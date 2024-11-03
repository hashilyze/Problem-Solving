// Beakjoon 1049 - 기타줄
// https://www.acmicpc.net/problem/1049

#include <algorithm>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int N, M;

inline int solution(int c1, int c6){
   return (c6 * (N / 6)) + std::min((c1 * (N % 6)), c6);
}

int main(void){
   FASTIO

   std::cin >> N >> M;
   int min1 = 2147483647, min6 = min1;
   for(int i = 0; i < M; ++i) {
      int c1, c6;
      std::cin >> c6 >> c1;
      min1 = std::min(min1, c1);
      min6 = std::min({min6, c6, c1 * 6});
   }
   std::cout << solution(min1, min6);

   return 0;
}   