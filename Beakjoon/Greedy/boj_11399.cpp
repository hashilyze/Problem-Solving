// Beakjoon 11399 - ATM 
// https://www.acmicpc.net/problem/11399

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int MAX_P = 1'000;
// variables
int N;
int arr[MAX_P + 1];


int solution(){
   int ret = 0;
   int delay = 0;
   for(int p = 1; p <= MAX_P; ++p){
      while(arr[p]){
         ret += delay + p;
         delay += p;
         --arr[p];
      }
   }
   return ret;
}

int main() { 
   FASTIO
   
   std::cin >> N;
   for(int i = 0; i < N; ++i) {
      int p;
      std::cin >> p;
      ++arr[p];
   }
   std::cout << solution();

   return 0; 
}