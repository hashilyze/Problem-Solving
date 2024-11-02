// Beakjoon 11497 - 통나무 건너뛰기
// https://www.acmicpc.net/problem/11497

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <deque>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int T, N;
std::priority_queue<int> heap;
std::deque<int> deq;


int solution(){
   deq.clear();

   int dist = 0;
   deq.push_back(heap.top()); heap.pop();
   while(!heap.empty()){
      if(heap.size() % 2){
         dist = std::max(dist, deq.front() - heap.top()); 
         deq.push_front(heap.top());
      } else{
         dist = std::max(dist, deq.back() - heap.top()); 
         deq.push_back(heap.top());
      }
      heap.pop();
   }
   dist = std::max(dist, std::abs(deq.front() - deq.back()));
   return dist;
}

int main() { 
   FASTIO

   std::cin >> T;
   for(int t = 0; t < T; ++t){
      std::cin >> N;
      for(int i = 0; i < N; ++i) {
         int elem;
         std::cin >> elem;
         heap.push(elem);
      }
      std::cout << solution() << '\n';
   }

   return 0; 
}