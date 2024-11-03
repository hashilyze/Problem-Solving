// Beakjoon 1969 - DNA
// https://www.acmicpc.net/problem/1969

#include <algorithm>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
const char DNA[4] = {'A', 'C', 'G', 'T'};
// variables
int N, M;
int votes[1'000][4];


int main(void){
   FASTIO

   std::cin >> N >> M;
   for(int i = 0; i < N; ++i){
      char ch;
      for(int j = 0; j < M; ++j) {
         std::cin >> ch;
         switch (ch) {
         case 'A': ++votes[j][0]; break;
         case 'C': ++votes[j][1]; break;
         case 'G': ++votes[j][2]; break;
         case 'T': ++votes[j][3]; break;
         }
      }
   }

   int sum = 0;
   for(int j = 0; j < M; ++j) {
      int maxIdx = std::max_element(votes[j], votes[j] + 4) - votes[j];
      for(int k = 0; k < 4; ++k) sum += votes[j][k];
      sum -= votes[j][maxIdx];

      std::cout << DNA[maxIdx];
   }
   std::cout << '\n' << sum;

   return 0;
}   