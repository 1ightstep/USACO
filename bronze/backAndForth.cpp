#include <bits/stdc++.h>
using namespace std;

set<int> aTankNums;

void generateAT(int d, int aT, vector<int> aB, int bT, vector<int> bB) {
    if (d == 4) {
        aTankNums.insert(aT);
        return;
    }
    if (d % 2 == 0) {
        for (int i = 0; i < aB.size(); i++) {
            int bucket = aB[i];
            vector<int> bBCopy = bB;
            vector<int> aBCopy = aB;
            bBCopy.push_back(bucket);
            aBCopy.erase(aBCopy.begin() + i);

            generateAT(d + 1, aT - bucket, aBCopy, bT + bucket, bBCopy);
        }
    } else {
        for (int i = 0; i < bB.size(); i++) {
            int bucket = bB[i];
            vector<int> bBCopy = bB;
            vector<int> aBCopy = aB;
            aBCopy.push_back(bucket);
            bBCopy.erase(bBCopy.begin() + i);

            generateAT(d + 1, aT + bucket, aBCopy, bT - bucket, bBCopy);
        }
    }

}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    vector<int> inpAB(10), inpBB(10); 
    for (int& i : inpAB) cin >> i; 
    for (int& i : inpBB) cin >> i;
    generateAT(0, 1000, inpAB, 1000, inpBB);
    cout << aTankNums.size();
}