#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    unordered_map<char, int> cows;
    map<char, pair<int, int>> cowPos; 
    
    for (int i = 0; i < 52; i++) {
        char cow; 
        cin >> cow; 
        if (cows.find(cow) == cows.end()) {
            cowPos[cow].first = i;
        } else {
            cowPos[cow].second = i;
        }
        cows[cow] ++; 
    }  

    int count = 0;
    for (auto cow1 : cowPos) {
        for (auto cow2 : cowPos) {
            if (cow2.first <= cow1.first) continue; 
            int a1 = cow1.second.first, a2 = cow1.second.second;
            int b1 = cow2.second.first, b2 = cow2.second.second;

            if ((a1 < b1 && b1 < a2 && a2 < b2) || (b1 < a1 && a1 < b2 && b2 < a2)) {
                count++;
            }
        }
    }

    cout << count;
}