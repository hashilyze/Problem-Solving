// [SWEA] 1940. 가랏! RC카!

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables


int main(int argc, char **argv) {
   FASTIO
   
   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      int N;
      std::cin >> N;

      int v = 0, s = 0;
      while(N--){
         int cmd = 0, x = 0;
         std::cin >> cmd;
         if(cmd != 0){
            std::cin >> x;
            if(cmd == 1) v += x;
            else if(cmd == 2) v = std::max(0, v - x);
         }
         s += v;
      }
      std::cout << '#' << t << ' ' << s << '\n';
   }

   return 0;
}