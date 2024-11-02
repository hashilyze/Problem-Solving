// Beakjoon 15903 - 카드 합체 놀이
// https://www.acmicpc.net/problem/15903

#include <iostream>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
using minHeap = std::priority_queue<ll,std::vector<ll>,std::greater<ll> >;
// constants
// variables
int N, M;
minHeap heap;

ll solution(){
   for(int i = 0; i < M; ++i){
      ll lhs = heap.top(); heap.pop();
      ll rhs = heap.top(); heap.pop();
      heap.push(lhs + rhs);
      heap.push(lhs + rhs);
   }
   ll sum = 0;
   for(int i = 0; i < N; ++i) {
      sum += heap.top(); heap.pop();
   }
   return sum;
}

int main() { 
   FASTIO

   std::cin >> N >> M;
   for(int i = 0; i < N; ++i) {
      int elem;
      std::cin >> elem;
      heap.push(elem);
   }
   std::cout << solution();

   return 0; 
}