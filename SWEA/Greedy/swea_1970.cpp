// [SWEA] 1970. 쉬운 거스름돈

#include <cstring>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
const int COINS[] = {  50'000, 10'000, 5'000, 1'000, 500, 100, 50, 10 };
constexpr int SIZE = sizeof(COINS) / sizeof(int);
// variables
int N;
int out[SIZE];


void solution(){
   for(int i = 0; i < SIZE; ++i){
      out[i] = N / COINS[i];
      N %= COINS[i];
   }
}

int main(int argc, char **argv) {
   FASTIO
   
   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::cin >> N;

      solution();     
      std::cout << '#' << t << '\n';
      for(int i = 0; i < SIZE; ++i) std::cout << out[i] << ' ';
      std::cout << '\n';
   }

   return 0;
}