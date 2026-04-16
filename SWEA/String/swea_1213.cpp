// [SWEA] 1213. [S/W 문제해결 기본] 3일차 - String

#include <iostream>
#include <string>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables

int solution(const std::string& word, const std::string& pattern){
   int cnt = 0;
   for(int i = 0; i < word.size() - pattern.size() + 1; ++i){
      if(word.compare(i, pattern.size(), pattern) == 0) ++cnt;
   }
   return cnt;
}

int main(int argc, char **argv) {
   FASTIO
   
   int T = 10;
   //std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::cin >> t;
      std::string p, w;
      std::cin >> p >> w;
      std::cout << '#' << t << ' ' << solution(w, p) << '\n';
   }

   return 0;
}