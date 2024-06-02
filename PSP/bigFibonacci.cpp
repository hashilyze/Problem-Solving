// 문제해결 기법 과제-33

#include <array>
#include <iostream>
#include <fstream>
#include <string>

// === File Control ====
const std::string FILE_NAME = "bigFibonacci";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";


constexpr int N = 2;
constexpr int MOD = 1000000007;

using ll = long long;
using mat = std::array<std::array<ll, N>, N>;


mat mul(const mat &lhs, const mat &rhs){
    mat ret = {0, 0, 0, 0};
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < N; ++k){
                ret[i][j] = (ret[i][j] + (ll)lhs[i][k] * rhs[k][j]) % MOD;
            }
        }
    }
    return ret;
}

mat sqrMat(ll n, const mat &m){
    if(n == 0) return {1, 0, 0, 1};
    if(n == 1) return m;

    mat r = sqrMat(n / 2, m);
    r = mul(r, r);
    if(n % 2) r = mul(r, m);
    return r;
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
    int T;
    in >> T;
    while(T--){
        ll n; 
        in >> n;
        auto m = sqrMat(n, {1, 1, 1, 0});
        out << n << ' ' << m[1][0] << '\n';
    }
#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}