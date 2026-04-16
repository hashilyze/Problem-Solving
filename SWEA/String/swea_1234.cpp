// [SWEA] 1234. [S/W 문제해결 기본] 10일차 - 비밀번호

#include <iostream>
#include <regex>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int N;
std::string S;


int main(int argc, char **argv) {
   FASTIO

   //int T; std::cin >> T;
   constexpr int T = 10;
   for(int t = 1; t <= T; ++t){
      std::cin >> N >> S;
      int l1, l2;
      do{
         l1 = S.size();
         S = std::regex_replace(S, std::regex("(00|11|22|33|44|55|66|77|88|99)"), "");
         l2 = S.size();
      } while(l1 != l2);
      std::cout << '#' << t << ' ' << S << '\n';
   }
   

   return 0;
}