// Beakjoon 20115 - 에너지 드링크
// https://www.acmicpc.net/problem/20115

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int N;


int main() { 
   FASTIO
   
   std::cin >> N;

   int max = 0, elem = 0;
   long long sum = 0LL;
   for(int i = 0; i < N; ++i){
      std::cin >> elem;
      sum += elem;
      max = std::max(max, elem);
   }
   sum += max;
   std::cout << (sum >> 1) << '.' << (sum & 1 ? '5' : '0');

   return 0; 
}