// Beakjoon 1783 - 병든 나이트
// https://www.acmicpc.net/problem/1783

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int N;   // 세로
int M;   // 가로

int solution(){
   if(N == 1) return 1;
   else if(N == 2) return std::min(4, (M + 1) >> 1); // M = 1 ~ 7
   else if(M < 7) return std::min(4, M);
   else return M - 2;
}

int main() { 
   FASTIO

   std::cin >> N >> M;
   std::cout << solution();

   return 0; 
}