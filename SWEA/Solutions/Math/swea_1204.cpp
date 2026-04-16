// [SWEA] 1204. [S/W 문제해결 기본] 1일차 - 최빈수 구하기

#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
const int NUM_STUDENT = 1'000;
const int RANGE = 100;
// variables
int freq[RANGE + 1];


int solution(){
   auto it = std::max_element(std::rbegin(freq), std::rend(freq));
   return std::rend(freq) - it - 1;
}


int main(int argc, char **argv) {
   FASTIO

   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::memset(freq, 0x00, sizeof(freq));

      std::cin >> t;
      for(int i = 0; i < NUM_STUDENT; ++i){
         int score;
         std::cin >> score;
         ++freq[score];
      }
      std::cout << '#' << t << ' ' << solution() << '\n';
   }

   return 0;
}