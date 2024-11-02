// Beakjoon 1946 - 신입 사원
// https://www.acmicpc.net/problem/1946

#include <iostream>
#include <utility>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
// variables
int T, N;
int arr[100'000];

int solution(){
   int cnt = 1;
   int min = arr[0];
   
   for(int i = 1; i < N; ++i){
      if(arr[i] < min) {
         min = arr[i];
         ++cnt;
      }
   }
   return cnt;
}

int main() { 
   FASTIO

   std::cin >> T;
   for(int t = 0; t < T; ++t){
      std::cin >> N;
      for(int i = 0; i < N; ++i) {
         int rank;
         std::cin >> rank >> arr[rank - 1];
      }
      std::cout << solution() << '\n';
   }

   return 0; 
}