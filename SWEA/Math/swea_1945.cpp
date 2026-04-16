// [SWEA] 1945. 간단한 소인수분해

#include <cstring>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int SIZE = 5;
const int PRIMES[SIZE] = {  2, 3, 5, 7, 11 };
// variables
int N;
int exponents[SIZE];


void solution(int n, int* exp){
   std::memset(exp, 0x00, sizeof(int) * SIZE);
   for(int i = 0; i < SIZE; ++i){
      int b = PRIMES[i], e = 0;
      while(n % b == 0){
         ++e;
         n /= b;
      }
      exp[i] = e;
   }
}

int main(int argc, char **argv) {
   FASTIO
   
   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::cin >> N;
      
      solution(N, exponents);
      
      std::cout << '#' << t << ' ';
      for(int i = 0; i < SIZE; ++i) std::cout << exponents[i] << ' ';
      std::cout << '\n';
   }

   return 0;
}