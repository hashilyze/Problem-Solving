// Beakjoon 1026 - 보물  
// https://www.acmicpc.net/problem/1026

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int N;
int digitsA[101];
int digitsB[101];


int solution(){
   int sum = 0;
   int dA = 100, dB = 0;
   for(int i = 0; i < N; ++i){
      while(digitsA[dA] == 0) --dA;
      while(digitsB[dB] == 0) ++dB;
      sum += dA * dB;
      --digitsA[dA];
      --digitsB[dB];
   }
   return sum;
}

int main(void){
   FASTIO

   std::cin >> N;
   for(int i = 0, e; i < N; ++i) {
      std::cin >> e;
      ++digitsA[e];
   }
   for(int i = 0, e; i < N; ++i) {
      std::cin >> e;
      ++digitsB[e];
   }
   std::cout << solution();

   return 0;
}   