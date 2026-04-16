// [SWEA] 1206. [S/W 문제해결 기본] 1일차 - View

#include <algorithm>
#include <iostream>
// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int MAX_N = 1'000;
// variables
int N;
int heights[MAX_N];


int solution(){
   int ret = 0;
   for(int i = 2; i < N - 2; ++i){
      int max = std::max({heights[i - 2], heights[i - 1], heights[i + 1], heights[i + 2]});
      ret += std::max(0, heights[i] - max);
   }
   return ret;
}

int main(int argc, char **argv) {
   FASTIO

   constexpr int T = 10;
   for(int t = 1; t <= T; ++t){
      std::cin >> N;
      for(int i = 0; i < N; ++i) std::cin >> heights[i];
      std::cout << '#' << t << ' ' << solution() << '\n';
   }

   return 0;
}