// Beakjoon 14247 - 나무 자르기
// https://www.acmicpc.net/problem/14247

#include <algorithm>
#include <iostream>
#include <utility>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
using pii = std::pair<int, int>;
// constants
// variables
int N;
pii arr[100'000];


ll solution(){
   ll sum = 0;
   std::sort(arr, arr + N);
   for(int i = 0; i < N; ++i){
      sum += arr[i].first * i + arr[i].second;
   }
   return sum;
}

int main() { 
   FASTIO
   
   std::cin >> N;
   for(int i = 0; i < N; ++i) std::cin >> arr[i].second;
   for(int i = 0; i < N; ++i) std::cin >> arr[i].first;
   std::cout << solution();

   return 0; 
}