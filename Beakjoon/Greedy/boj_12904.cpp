// Beakjoon 12904 - A와 B
// https://www.acmicpc.net/problem/12904

#include <algorithm>
#include <iostream>
#include <string>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
std::string S, T;

int solution(){
   while(S.size() < T.size()){
      char ch = T.back(); T.pop_back();
      if(ch == 'B') std::reverse(T.begin(), T.end());
   }
   return S == T ? 1 : 0;
}

int main(void){
   FASTIO

   std::cin >> S >> T;
   std::cout << solution();

   return 0;
}   