#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    int n; 
    cin >> n;

    string currAnimal;
    vector<int> k(n);
    vector<vector<string>> c(n);
    for (int i = 0; i < n; i++) {
        cin >> currAnimal;
        cin >> k[i];
        c[i].resize(k[i]);
        for (int j = 0; j < k[i]; j++) {
            cin >> c[i][j];
        }
    }

    int maxYes = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int count = 0;
            unordered_set<string> traits(c[i].begin(), c[i].end());
            for (string trait : c[j]) {
                if (traits.count(trait)) count ++;
            }
            maxYes = max(maxYes, count);
        } 
    }

    cout << maxYes + 1;
}