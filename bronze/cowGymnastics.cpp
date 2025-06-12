#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int n, k; 
    cin >> n >> k; 
    
    vector<vector<int>> cows(n, vector<int>(k));
    for (vector<int>& row : cows) {
        for (int& cow : row) {
            cin >> cow;
        }
    }
    
    map<pair<int, int>, int> frequency; 
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int o = j + 1; o < k; o++) {
                if (frequency.find({cows[i][j], cows[i][o]}) == frequency.end())
                    frequency[{cows[i][j], cows[i][o]}] = 0; 
                frequency[{cows[i][j], cows[i][o]}] ++;
            }
        }
    }

    int count = 0;
    for (auto& p : frequency) {
        if (p.second == n)
            count ++;
    }

    cout << count;
}