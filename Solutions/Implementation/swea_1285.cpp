// [SWEA] 1285. 아름이의 돌 던지기

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>
#include <tuple>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
constexpr int SIZE = 100'001;
// variables
int N;
int freq[SIZE];


pii solution(){
   auto p = std::find_if(freq, freq + SIZE, [](int e) { return e != 0; });
   return { p - freq, *p };
}

int main(int argc, char **argv) {
   FASTIO
   
   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::memset(freq, 0x00, sizeof(freq));

      std::cin >> N;
      for(int i = 0; i < N; ++i) {
         int dist;
         std::cin >> dist;
         ++freq[std::abs(dist)];
      }

      int d, f;
      std::tie(d, f) = solution();
      std::cout << '#' << t << ' ' << d << ' ' << f << '\n';
   }

   return 0;
}