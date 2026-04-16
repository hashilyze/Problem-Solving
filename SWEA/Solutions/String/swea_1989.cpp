// [SWEA] 1989. 초심자의 회문 검사

#include <iostream>
#include <string>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
std::string S;


inline bool isPalindrome(const std::string& s){
   int lcur = 0, rcur = s.size() - 1;
   while(lcur < rcur){
      if(s[lcur++] != s[rcur--]) return false;
   }
   return true;
}

int main(int argc, char **argv) {
   FASTIO

   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::cin >> S;
      std::cout << '#' << t << ' '
         << (isPalindrome(S) ? 1 : 0) << '\n';
   }

   return 0;
}