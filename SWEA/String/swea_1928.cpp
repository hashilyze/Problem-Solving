// [SWEA] 1928. Base64 Decoder

#include <iostream>
#include <string>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
std::string from, to;


inline char base64Decode(char ch){
   if('A' <= ch && ch <= 'Z') return ch - 'A';
   else if('a' <= ch && ch <= 'z') return ch - 'a' + 26;
   else if('0' <= ch && ch <= '9') return ch - '0' + 52;
   else if(ch == '+') return 62;
   else if(ch == '/') return 63;
   return -1;
}

void solution(const std::string& from, std::string& to){
   to.clear();
   to.reserve((from.size() * 6) >> 3);

   int bit = 0, bitLen = 0;
   for(char ch : from){
      ch = base64Decode(ch);

      bit <<= 6;
      bit |= ch;
      bitLen += 6;
      if(bitLen >= 8){
         switch (bitLen) {
         case 8:  { to.push_back(bit >> 0); bit &= 0x00; } break;
         case 10: { to.push_back(bit >> 2); bit &= 0x03; } break;
         case 12: { to.push_back(bit >> 4); bit &= 0x0F; } break;
         }
         bitLen -= 8;
      }
   }
}

int main(int argc, char **argv) {
   FASTIO
   
   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::cin >> from;
      solution(from, to);
      std::cout << '#' << t << ' ' << to << '\n';
   }

   return 0;
}