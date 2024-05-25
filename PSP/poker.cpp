// 문제해결기법 - 30

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>

// === File Control ====
//#define ONLINE_JUDGE
const std::string FILE_NAME = "poker";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";

// types
using pcc = std::pair<char, char>;
// constants
constexpr int MAX_N = 7;
// variables
std::vector<pcc> cards(MAX_N, {0, 0}); // (number, pattern)


std::string getRank(std::vector<pcc> &pool, bool onlyStright = false){
    // rank
    int top = 0, pair = 0, triple = 0, fourCard = 0;
    bool straight = false, fullHouse = false, flush = false;
    bool straightFlush = false;

    // aggregation.
    int values[14] = {0, }, patterns[4]= {0, };
    {
        std::sort(pool.begin(), pool.end());
        for(const pcc &card : pool){
            ++patterns[card.second];
            ++values[card.first - 1];
        }
        values[13] = values[0];
    }
    // case.1: pair, triple, four-card, full-house
    if(!onlyStright)
    {
        for(int i = 0; i < 13; ++i){
            switch(values[i]){
            case 1: ++top; break;
            case 2: ++pair; break;
            case 3: ++triple; break;
            case 4: ++fourCard; break;
            }
        }
        fullHouse = (pair && triple) || triple >= 2;
    }

    // case.2: stright
    {
        int maxLen = 0;
        int lCur = 0, rCur = 0;
        while(rCur < 14){
            if(values[rCur] == 0) {
                maxLen = std::max(maxLen, rCur - lCur);
                lCur = ++rCur;
            } else{
                ++rCur;
            }
        }
        maxLen = std::max(maxLen, rCur - lCur);
        straight = maxLen >= 5;
    }

    // case.3: flush
    if(!onlyStright) {
        int *it = std::find_if(patterns, patterns + 4, [](int p) { return p >= 5;});
        flush = it != patterns + 4;
        if(flush){
            std::vector<pcc> flushHand;
            for(const pcc &card : pool){
                if(card.second == it - patterns) flushHand.push_back(card);
            }
            straightFlush = getRank(flushHand, true) == "Straight";
        }
    }
    
    if(straightFlush) return "Straight Flush";
    if(fourCard) return "Four Card";
    if(fullHouse) return "Full House";
    if(flush) return "Flush";
    if(straight) return "Straight";
    if(triple) return "Triple";
    if(pair >= 2) return "Two Pair";
    if(pair) return "One Pair";
    return "Top";
}

int patternId(char ch){
    switch(ch){
    case 'S': return 0;
    case 'D': return 1;
    case 'H': return 2;
    case 'C': return 3;
    }
    return -1;
}
int valueId(char ch){
    switch (ch) {
    case 'K': return 13;
    case 'Q': return 12;
    case 'J': return 11;
    case 'T': return 10;
    case 'A': return 1;
    }
    return ch - '0';
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
        for(int i = 0; i < MAX_N; ++i) {
            in >> cards[i].second >> cards[i].first;
            cards[i].second = patternId(cards[i].second);
            cards[i].first = valueId(cards[i].first);
        }
        out << getRank(cards) << '\n';
    }
#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}