// Beakjoon 1931 - 회의실 배정
// https://www.acmicpc.net/problem/1931

#include <algorithm>
#include <iostream>
#include <utility>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
constexpr int MAX_N = 100'000;
// variables
int N;
pii arr[MAX_N];


int solution(){
   int cnt = 0;
   int last = 0;
   for(int i = 0; i < N; ++i){
      if(last <= arr[i].second){
         ++cnt;
         last = arr[i].first;
      }
   }
   return cnt;
}

int main() { 
   FASTIO
   
   std::cin >> N;
   for(int i = 0; i < N; ++i) std::cin >> arr[i].second >> arr[i].first;
   std::sort(arr, arr + N);
   std::cout << solution();

   return 0; 
}