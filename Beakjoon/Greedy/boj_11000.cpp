// Beakjoon 11000 - 강의실 배정
// https://www.acmicpc.net/problem/11000

#include <algorithm>
#include <iostream>
#include <utility>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
// variables
int N;
pii arr[400'000];


int solution(){
   std::sort(arr, arr + N * 2);
   int max = 0, cnt = 0;
   for(int i = 0; i < 2 * N; ++i){
      if(arr[i].second){ // start
         ++cnt;
      } else{ // end
         max = std::max(max, cnt);
         --cnt;
      }
   }
   return max;
}

int main(void){
   FASTIO

   std::cin >> N;
   for(int i = 0; i < N; ++i){
      int s, t;
      std::cin >> s >> t;
      arr[i * 2] = {s, 1};
      arr[i * 2 + 1] = {t, 0};
   }
   std::cout << solution();

   return 0;
}   