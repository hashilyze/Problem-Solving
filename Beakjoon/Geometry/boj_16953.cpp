// Beakjoon 16953 - A → B
// https://www.acmicpc.net/problem/16953

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables


int main() { 
   FASTIO
   
   int A, B;
   std::cin >> A >> B;

   int cnt = 1;
   while(A < B){
      ++cnt;
      if(B % 10 == 1) B = (B - 1) / 10;
      else if(B % 2 == 0) B >>= 1;
      else break;
   }
   std::cout << (A == B ? cnt : -1);
   

   return 0; 
}