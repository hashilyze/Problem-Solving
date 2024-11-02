// Beakjoon 11501 - 주식
// https://www.acmicpc.net/problem/11501

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
// variables
int N;
int arr[1'000'000];

ll solution(){
   ll sum = 0LL;
   int max = 0;
   for(int i = N - 1; i >= 0; --i){
      max = std::max(arr[i], max);
      sum += max - arr[i];
   }
   return sum;
}

int main() { 
   FASTIO
   
   int T;
   std::cin >> T;
   while(T--){
      std::cin >> N;
      for(int i = 0; i < N; ++i) std::cin >> arr[i];
      std::cout << solution() << '\n';
   }

   return 0; 
}