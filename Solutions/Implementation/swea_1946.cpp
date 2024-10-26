// [SWEA] 1946. 간단한 압축 풀기

#include <iostream>
#include <string>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int LINE = 10;
// variables


void appendWord(std::string& doc, char C, int K){
   int left = (LINE + 1) - doc.size() % (LINE + 1) - 1;
   while(K > 0){
      int append = std::min(K, left);
      
      doc.append(append, C);
      if(left == append) doc.append("\n");
      K -= append;
      left = LINE;
   }
}

int main(int argc, char **argv) {
   FASTIO
   
   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      int N = 0; 
      std::cin >> N;

      char C = '\0'; 
      int K = 0;
      std::string doc;
      while(N--){
         std::cin >> C >> K;
         appendWord(doc, C, K);
      }
      if(doc.size() % (LINE + 1)) doc.append("\n");
      std::cout << '#' << t << '\n' << doc;
   }

   return 0;
}