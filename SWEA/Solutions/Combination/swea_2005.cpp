// [SWEA] 2005. 파스칼의 삼각형

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
const int MAX_N = 10;
// variables
int comb[MAX_N + 1][MAX_N + 1];


void init(){
   comb[0][0] = 1;
   for(int n = 1; n <= MAX_N; ++n){
      for(int k = 0; k <= MAX_N; ++k){
         comb[n][k] = comb[n - 1][k] + comb[n - 1][k - 1];
      }
   }
}

int main(int argc, char **argv) {
   FASTIO
   init();

   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      int N;
      std::cin >> N;
      
      std::cout << '#' << t << '\n';
      for(int n = 0; n < N; ++n){
         for(int k = 0; k <= n; ++k){
            std::cout << comb[n][k] << ' ';
         }
         std::cout << '\n';
      }
   }

   return 0;
}