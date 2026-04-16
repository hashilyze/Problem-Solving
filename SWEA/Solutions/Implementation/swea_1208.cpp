// [SWEA] 1208. [S/W 문제해결 기본] 1일차 - Flatten

#include <algorithm>
#include <cstring>
#include <iostream>
// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int T = 10;
constexpr int N = 100;
// variables
int dump;
int freq[N + 1];


int solution(){
   int left = dump;
   int min = 1, max = 100;
   
   while(left > 0){
      while(freq[min] == 0) ++min;
      while(freq[max] == 0) --max;
      if(max - min <= 1) break;
      
      int mv = std::min({freq[min], freq[max], left});
      freq[min] -= mv; freq[min + 1] += mv;
      freq[max] -= mv; freq[max - 1] += mv;
      left -= mv;
   }
   while(freq[min] == 0) ++min;
   while(freq[max] == 0) --max;

   return max - min;
}

int main(int argc, char **argv) {
   FASTIO

   for(int t = 1; t <= T; ++t){
      std::memset(freq, 0x00, sizeof(freq));

      std::cin >> dump;
      for(int i = 0, h; i < N; ++i) {
         std::cin >> h;
         ++freq[h];
      }
      std::cout << '#' << t << ' ' << solution() << '\n';
   }

   return 0;
}