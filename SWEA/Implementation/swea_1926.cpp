// [SWEA] 1926. 간단한 369게임

#include <iostream>
#include <string>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables

inline int countClap(int n){
   int cnt = 0;
   while(n > 0){
      int d = n % 10;
      if(d != 0 && d % 3 == 0) 
         ++cnt;
      n /= 10;
   }
   return cnt;
}

int main(int argc, char **argv) {
   FASTIO

   int N;
   std::cin >> N;
   for(int i = 1; i <= N; ++i){
      int cnt = countClap(i);
      if(cnt) std::cout << std::string(cnt, '-') << ' ';
      else std::cout << i << ' ';
   }

   return 0;
}