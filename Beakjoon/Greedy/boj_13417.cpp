// Beakjoon 13417 - 카드 문자열
// https://www.acmicpc.net/problem/13417

#include <deque>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables


int main() { 
   FASTIO
   
   int T;
   std::cin >> T;
   while(T--){
      int N;
      std::deque<char> deq;
      std::cin >> N;

      char ch;
      std::cin >> ch;
      deq.push_back(ch);
      for(int i = 1; i < N; ++i) {
         std::cin >> ch;
         if(ch <= deq.front()) deq.push_front(ch);
         else deq.push_back(ch);
      }

      for(int i = 0; i < N; ++i) std::cout << deq[i];
      std::cout << '\n';
   }

   return 0; 
}