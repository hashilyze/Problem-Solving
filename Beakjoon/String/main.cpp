// Beakjoon 1141 - 접두사
// https://www.acmicpc.net/problem/1141

#include <algorithm>
#include <iostream>
#include <string>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int N;
std::string words[50];


int solution(){
   std::sort(words, words + N);
   int cnt = N;
   
   for(int i = 1; i < N; ++i){
      const std::string &l = words[i - 1], &r = words[i];
      if(l.size() <= r.size() && r.compare(0, l.size(), l) == 0) --cnt;
   }
   return cnt;
}

int main() { 
   FASTIO

   std::cin >> N;
   for(int i = 0; i < N; ++i) std::cin >> words[i];
   std::cout << solution();

   return 0; 
}