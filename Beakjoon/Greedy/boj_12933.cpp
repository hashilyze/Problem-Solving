// Beakjoon 12933 - 오리
// https://www.acmicpc.net/problem/12933

#include <algorithm>
#include <iostream>
#include <string>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
std::string str;


int solution(){
   int cnt = 0;
   int q = 0, u = 0, a = 0, c = 0, k = 0;
   for(char ch : str){
      switch (ch) {
      case 'q': ++q; break;
      case 'u': ++u; break;
      case 'a': ++a; break;
      case 'c': ++c; break;
      case 'k': ++k; break;
      }

      if(!(q >= u && u >= a && a >= c && c >= k)) return -1;
      if(ch == 'k'){
         cnt = std::max(cnt, q);
         --q; --u; --a; --c; --k;
      }
   }
   if(q | u | a | c | k) return -1;
   return cnt;
}

int main() { 
   FASTIO
   
   std::cin >> str;
   std::cout << solution();

   return 0; 
}