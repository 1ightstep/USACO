#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m; 
    cin >> n >> m; 

    vector<vector<char>> spots(n, vector<char>(m));
    vector<vector<char>> noSpots(n, vector<char>(m));
    for (vector<char>& s : spots) {
        for (char& g : s)
            cin >> g; 
    }
    for (vector<char>& s : noSpots) {
        for (char& g : s)
            cin >> g; 
    }

    int count = 0;
    for (int i = 0; i < m; i++) {    
        unordered_map<char, int> sF = {};
        unordered_map<char, int> nsF = {}; 

        for (int j = 0; j < n; j++) {
            if (sF.find(spots[j][i]) == sF.end())
                sF[spots[j][i]] = 1; 
            if (nsF.find(noSpots[j][i]) == nsF.end())
                nsF[noSpots[j][i]] = 1;
        }

        bool allDiff = true;
        for (auto f : sF) {
            if (nsF.find(f.first) != nsF.end()) {
                allDiff = false;
                break;
            }
        }

        count += allDiff; 
    }

    cout << count;
}