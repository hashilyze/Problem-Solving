// [SWEA] 1284. 수도 요금 경쟁

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables


int solution(int P, int Q, int R, int S, int W){
   return std::min(W * P, Q + std::max(W - R, 0) * S);
}

int main(int argc, char **argv) {
   FASTIO

   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      int P, Q, R, S, W;
      std::cin >> P >> Q >> R >> S >> W;
      std::cout << '#' << t << ' ' << solution(P, Q, R, S, W) << '\n';
   }

   return 0;
}