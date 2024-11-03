// Beakjoon 2885 - 초콜릿 식사
// https://www.acmicpc.net/problem/2885

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables

std::pair<int, int> solution(int k){
   int n = 1, cnt = 0;
   while(n < k) n <<= 1;
      
   int x = n;
   while(k){
      if(k - x >= 0) k -= x;
      x >>= 1;
      ++cnt;
   }
   return {n, cnt};
}

int main() { 
   FASTIO
   
   int K;
   std::cin >> K;
   auto ret = solution(K);
   std::cout << ret.first << ' ' << ret.second;

   return 0; 
}