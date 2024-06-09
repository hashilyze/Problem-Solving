// 문제해결 기법 과제-34

#include <algorithm>
#include <cctype>
#include <cstring>
#include <deque>
#include <iostream>
#include <string>

//#define ONLINE_JUDGE

using BigInt = std::deque<int>;
// Decl
struct Decimal;

// arithmetic - DEC
Decimal add(Decimal &lhs, Decimal &rhs);
Decimal sub(Decimal &lhs, Decimal &rhs);
Decimal mul(Decimal &lhs, Decimal &rhs);
Decimal div(Decimal &lhs, Decimal &rhs);
// arithmetic - STR
Decimal add(const std::string &lStr, const std::string &rStr);
Decimal sub(const std::string &lStr, const std::string &rStr);
Decimal mul(const std::string &lStr, const std::string &rStr);
Decimal div(const std::string &lStr, const std::string &rStr);
// utility
void adjust(Decimal &lhs, Decimal &rhs);
void normalize(Decimal &dec);
int comp(const Decimal &lhs, const Decimal &rhs);


struct Decimal{
    Decimal() = default;
    Decimal(const std::string &str) {
        // sign
        sign = str[0] == '-';
        // exponent
        auto it = std::find(str.crbegin(), str.crend(), '.');
        if(it != str.crend()) exp = it - str.crbegin();
        // fractional
        int cur = str.size() - 1;
        while(cur >= 0){
            if(std::isdigit(str[cur])) {
                digits.push_back(str[cur] - '0');
            }
            --cur;
        }
        if(exp == digits.size()) digits.push_back(0);
        normalize(*this);
    }

    std::string toString();
public:
    bool sign = 0;
    int exp = 0;
    BigInt digits;
};

std::string Decimal::toString(){
    std::string str; str.reserve(digits.size() + 2);

    if(sign) str.push_back('-');
    for(int i = digits.size() - 1; i >= exp; --i) str.push_back(digits[i] + '0');
    if(exp > 0) str.push_back('.');
    for(int i = exp - 1; i >= 0; --i) str.push_back(digits[i] + '0');
    return str;
}

// utility
void adjust(Decimal &lhs, Decimal &rhs){
    // fraction padding
    if(lhs.exp < rhs.exp) lhs.digits.insert(lhs.digits.begin(), rhs.exp - lhs.exp, 0);
    else if(lhs.exp > rhs.exp) rhs.digits.insert(rhs.digits.begin(), lhs.exp - rhs.exp, 0);
    // integer padding
    if(lhs.digits.size() < rhs.digits.size()) lhs.digits.insert(lhs.digits.end(), rhs.digits.size() - lhs.digits.size(), 0);
    else if(lhs.digits.size() > rhs.digits.size()) rhs.digits.insert(rhs.digits.end(), lhs.digits.size() - rhs.digits.size(), 0);
}
std::pair<Decimal, Decimal> makeAdjust(const Decimal &clhs, const Decimal &crhs){
    Decimal lhs = clhs, rhs = crhs;
    // fraction padding
    if(lhs.exp < rhs.exp) lhs.digits.insert(lhs.digits.begin(), rhs.exp - lhs.exp, 0);
    else if(lhs.exp > rhs.exp) rhs.digits.insert(rhs.digits.begin(), lhs.exp - rhs.exp, 0);
    // integer padding
    if(lhs.digits.size() < rhs.digits.size()) lhs.digits.insert(lhs.digits.end(), rhs.digits.size() - lhs.digits.size(), 0);
    else if(lhs.digits.size() > rhs.digits.size()) rhs.digits.insert(rhs.digits.end(), lhs.digits.size() - rhs.digits.size(), 0);
    return {lhs, rhs};
}
void normalize(Decimal &dec){
    int cur = 0;
    // trim fraction
    while(cur < dec.exp && dec.digits[cur] == 0) ++cur;
    dec.digits.erase(dec.digits.begin(), dec.digits.begin() + cur);
    dec.exp -= cur;
    // trim integer
    cur = dec.digits.size() - 1;
    while(cur >= dec.exp && dec.digits[cur] == 0) --cur;
    dec.digits.erase(dec.digits.begin() + cur + 1, dec.digits.end());

    if(dec.digits.size() - dec.exp == 0) dec.digits.push_back(0);
    if(dec.digits.size() == 1 && dec.digits[0] == 0) dec.sign = 0;
}
int comp(const Decimal &lhs, const Decimal &rhs){
    if(lhs.sign != rhs.sign) return lhs.sign ? -1 : 1;
    auto r = makeAdjust(lhs, rhs);
    const Decimal &clhs = r.first, &crhs = r.second;

    int lcur = clhs.digits.size() - 1, rcur = crhs.digits.size() - 1;
    while(lcur >= 0 && rcur >= 0){
        int diff = clhs.digits[lcur] - crhs.digits[rcur];
        if(diff) return diff < 0 ? -1 : 1;
        --lcur; --rcur;
    }
    if(lcur >= 0) return 1;
    if(rcur >= 0) return -1;

    return 0;
}


// === Decimal ===
Decimal add(Decimal &lhs, Decimal &rhs) {
    // (+) + (-) => (+) - (+)
    if(lhs.sign && !rhs.sign) { lhs.sign = 0; return sub(rhs, lhs); } 
    if(!lhs.sign && rhs.sign) { rhs.sign = 0; return sub(lhs, rhs); } 
    
    adjust(lhs, rhs);
    Decimal result;
    result.sign = lhs.sign;
    result.exp = std::max(lhs.exp, rhs.exp);

    BigInt &leftDigit = lhs.digits, &rightDigit = rhs.digits, &resultDigit = result.digits;
    int cur = 0, carry = 0;
    while((cur < leftDigit.size() && cur < rightDigit.size()) || carry){
        int sum = 0;
        if(cur < leftDigit.size()) sum += leftDigit[cur];
        if(cur < rightDigit.size()) sum += rightDigit[cur];
        sum += carry;

        resultDigit.push_back(sum % 10);
        carry = sum / 10;
        ++cur;
    }
    normalize(result);

    return result;
}
Decimal sub(Decimal &lhs, Decimal &rhs) {
    if(lhs.sign != rhs.sign){ rhs.sign = lhs.sign; return add(lhs, rhs); }
    adjust(lhs, rhs);

    Decimal result;
    result.sign = lhs.sign;
    result.exp = std::max(lhs.exp, rhs.exp);
    
    lhs.sign = rhs.sign = 0;
    int diff = comp(lhs, rhs);
    if(diff < 0) {
        std::swap(lhs, rhs);
        result.sign = !result.sign;
    }

    BigInt &leftDigit = lhs.digits, &rightDigit = rhs.digits, &resultDigit = result.digits;
    int cur = 0, carry = 0;
    while(cur < leftDigit.size() && cur < rightDigit.size()){
        int sum = leftDigit[cur] - rightDigit[cur] - carry;
        carry = sum < 0 ? 1 : 0;
        if(sum < 0) sum += 10;
        resultDigit.push_back(sum);
        ++cur;
    }
    normalize(result);

    return result;
}
Decimal mul(Decimal &lhs, Decimal &rhs){
    Decimal result;
    result.sign = lhs.sign == rhs.sign ? 0 : 1;
    result.exp = lhs.exp + rhs.exp;

    BigInt &leftDigit = lhs.digits, &rightDigit = rhs.digits, &resultDigit = result.digits;
    resultDigit.resize(leftDigit.size() + rightDigit.size() + 1);
    for(int i = 0; i < leftDigit.size(); ++i){
        for(int j = 0; j < rightDigit.size(); ++j){
            int sum = leftDigit[i] * rightDigit[j] + resultDigit[i + j];
            resultDigit[i + j] = sum % 10;
            resultDigit[i + j + 1] += sum / 10;
        }
    }
    normalize(result);
    return result;
}
Decimal div(Decimal &lhs, Decimal &rhs){
    Decimal result;
    bool sign = lhs.sign == rhs.sign ? 0 : 1;
    lhs.sign = rhs.sign = 0;
    

    int maxLen;
    {
        maxLen = (lhs.digits.size() - lhs.exp + rhs.exp);
        int zeros = 0;
        while(rhs.digits[rhs.digits.size() - 1 - zeros] == 0) ++zeros;
        maxLen -= rhs.digits.size() - 1 - zeros;
    }
    result.digits.resize(std::max(maxLen + 1, 0));
    for(int i = maxLen - 1; i >= 0; --i){
        int diff;
        while((diff = comp(mul(result, rhs), lhs)) < 0 && result.digits[i] <= 10){
            ++result.digits[i];
        }
        if(diff > 0) result.digits[i] = std::max(result.digits[i] - 1, 0);
    }
    result.sign = sign;
    normalize(result);
    return result;
}


// === String Adaptor ===
Decimal add(const std::string &lStr, const std::string &rStr) {
    Decimal lhs(lStr), rhs(rStr);
    return add(lhs, rhs);
}
Decimal sub(const std::string &lStr, const std::string &rStr) {
    Decimal lhs(lStr), rhs(rStr);
    return sub(lhs, rhs);
}
Decimal mul(const std::string &lStr, const std::string &rStr) {
    Decimal lhs(lStr), rhs(rStr);
    return mul(lhs, rhs);
}
Decimal div(const std::string &lStr, const std::string &rStr) {
    Decimal lhs(lStr), rhs(rStr);
    return div(lhs, rhs);
}

int main(void){
#ifndef ONLINE_JUDGE
    std::freopen("double.inp", "r", stdin);
    std::freopen("double.out", "w", stdout);
#endif

    int T;
    std::cin >> T;
    while(T--){
        char op;
        std::string lhs, rhs;

        std::cin >> lhs >> op >> rhs;
        switch (op) {
        case '+': std::cout << add(lhs, rhs).toString() << '\n'; break;
        case '-': std::cout << sub(lhs, rhs).toString() << '\n'; break;
        case '*': std::cout << mul(lhs, rhs).toString() << '\n'; break;
        case '/': std::cout << div(lhs, rhs).toString() << '\n'; break;
        }
    }
    return 0;
}