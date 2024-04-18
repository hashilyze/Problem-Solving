// Beakjoon 9417번 - 최대 GCD
// https://www.acmicpc.net/problem/9417

#include <iostream>
#include <string>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;


ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


int main(void){
    FASTIO

    ll n;
    std::cin >> n;
    while(n--){
        ll repeatCnt = 0, nonRepeatCnt = 0;
        ll repeat = 0, nonRepeat = 0;

        std::string line;
        std::cin >> line;


        ll cursor = 2;
        while(cursor < line.size() && std::isdigit(line[cursor])){
            nonRepeat = nonRepeat * 10 + (line[cursor] - '0');
            ++nonRepeatCnt;
            ++cursor;
        }
        if(cursor < line.size() && line[cursor] == '('){
            ++cursor;
            repeat = nonRepeat;
            while(cursor < line.size() && std::isdigit(line[cursor])){
                repeat = repeat * 10 + (line[cursor] - '0');
                ++repeatCnt;
                ++cursor;
            }
        }
        

        ll divisor, dividend;
        if(repeatCnt != 0){
            divisor = repeat - nonRepeat;
        } else{
            divisor = nonRepeat;
        }
        
        dividend = 0;
        for(ll i = 0; i < repeatCnt; ++i){
            dividend *= 10;
            dividend += 9;
        }
        if(dividend == 0) dividend = 1;
        for(ll i = 0; i < nonRepeatCnt; ++i){
            dividend *= 10;
        }

        ll d = (divisor >= dividend) ? gcd(divisor, dividend) : gcd(dividend, divisor);
        std::cout << divisor / d << '/' << dividend / d << '\n';
    }


    return 0;
}