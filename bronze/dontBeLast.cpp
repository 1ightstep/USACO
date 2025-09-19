#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    int n; 
    cin >> n;

    vector<string> cowNames = {
        "Bessie", "Elsie", "Daisy", "Gertie",
        "Annabelle", "Maggie", "Henrietta"
    };

    unordered_map<string, int> cows;

    for (string cow : cowNames) cows[cow] = 0; 
    for (int  i = 0; i < n; i++) {
       string name;
       int amt;
       cin >> name >> amt; 
       cows[name] += amt; 
    }

    unordered_map<int, int> freqAmt;
    vector<int> totalAmt;
    for (auto &[name, amt] : cows) {
        totalAmt.push_back(amt);
        freqAmt[amt] ++;
    }
    std::sort(totalAmt.begin(), totalAmt.end());
    totalAmt.erase(unique(totalAmt.begin(), totalAmt.end()), totalAmt.end());

    int target = totalAmt[1];
    if (totalAmt.size() < 2 || freqAmt[target] > 1) {
        cout << "Tie" << endl;
        return 0;
    }   

    for (auto &[name, amt] : cows) {
        if (amt == target) {
            cout << name << endl;
            return 0;
        }
    }

}