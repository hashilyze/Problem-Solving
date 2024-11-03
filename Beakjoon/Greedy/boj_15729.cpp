// Beakjoon 15729 - 방탈출
// https://www.acmicpc.net/problem/15729

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int N;
char bulbs[1'000'000];


int solution(){
   int cnt = 0;
   for(int i = 0; i < N; ++i){
      if(bulbs[i] != '0') {
         ++cnt;
         for(int j = i; j < std::min(N, i + 3); ++j){
            bulbs[j] ^= 1;
         }
      }
   }
   return cnt;
}

int main() { 
   FASTIO
   
   std::cin >> N;
   for(int i = 0; i < N; ++i) std::cin >> bulbs[i];
   std::cout << solution();

   return 0; 
}