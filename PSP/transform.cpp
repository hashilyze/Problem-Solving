// 문제해결기법 과제-32

#include <algorithm>
#include <cstring>
#include <iostream>
#include <fstream>
#include <stack>

// === File Control ====
const std::string FILE_NAME = "transform";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";
// variables
std::string parenthesis;
std::vector<int> inorder;

void transformInorder(){
    std::stack<int> s;
    int id = 0;
    for(char ch : parenthesis){
        if(ch == '('){
            s.push(++id);
        } else {
            inorder.push_back(s.top());
            s.pop();
        }
    }
}

void transformTree(int beg, int end){
    if(beg >= end) return;
    int pos = std::min_element(inorder.begin() + beg, inorder.begin() + end) - inorder.begin();
    parenthesis.push_back('(');
    transformTree(beg, pos);
    parenthesis.push_back(')');
    transformTree(pos + 1, end);
}

int main(void){
#ifndef ONLINE_JUDGE
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);
    std::istream& in = fin;
    std::ostream& out = fout;
#else
    std::istream& in = std::cin;
    std::ostream& out = std::cout;
#endif
    int t;
    in >> t;
    while(t--){
        int N, K;
        in >> N >> K;
        
        switch(K){
        case 0:{
            inorder.resize(N);
            for(int i = 0; i < N; ++i) in >> inorder[i];

            parenthesis.clear();
            transformTree(0, N);
            out << N << ' ' << parenthesis << '\n';
        } break;
        case 1:{
            in >> parenthesis;
            inorder.clear();
            
            transformInorder();
            out << N;
            for(int i = 0; i < N; ++i) out << ' ' << inorder[i];
            out << '\n';
        } break;
        }
    }
#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}