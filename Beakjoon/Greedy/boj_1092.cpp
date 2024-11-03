// Beakjoon 1092 - 배
// https://www.acmicpc.net/problem/1092

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using MinHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>;
// constants
// variables
int N, M;
int Containers[51];
int Boxes[10'000];


int solution(){
   std::sort(Containers, Containers + N, std::greater<int>());
   std::sort(Boxes, Boxes + M, std::greater<int>());
   if(Containers[0] < Boxes[0]) return -1;

   int max = 0;
   int j = 0;
   MinHeap heap;
   for(int i = 1; i <= N; ++i){
      int lower_bound = Containers[i];
      heap.push(0);

      while(j < M && lower_bound < Boxes[j]){
         int p = heap.top() + 1;
         heap.pop();
         heap.push(p);
         ++j;
         max = std::max(max, p);
      }
   }
   return max;
}

int main(void){
   FASTIO
   
   std::cin >> N;
   for(int i = 0; i < N; ++i) std::cin >> Containers[i];
   std::cin >> M;
   for(int i = 0; i < M; ++i) std::cin >> Boxes[i];
   std::cout << solution();

   return 0;
}   