#include <bits/stdc++.h>
using namespace std;

void didWin(set<char> v, set<char> h, set<set<char>> &indWins, set<set<char>> &teamWins) {
    switch (v.size()) {
        case 1:
            indWins.insert(v);
            break;
        case 2: 
            teamWins.insert(v);
            break;
    }
    switch (h.size()) {
        case 1:
            indWins.insert(h);
            break;
        case 2: 
            teamWins.insert(h);
            break;
    }
}

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    
    vector<string> grid(3);
    for (string &i : grid)
        cin >> i;
    
    set<set<char>> indWins;  
    set<set<char>> teamWins;
    set<char> v;
    set<char> h; 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            v.insert(grid[i][j]);
            h.insert(grid[j][i]);
        }
        didWin(v, h, indWins, teamWins);
        v = {};
        h = {};
    }
    
    v = {grid[0][0], grid[1][1], grid[2][2]};
    h = {grid[0][2], grid[1][1], grid[2][0]};
    didWin(v, h, indWins, teamWins);
    cout << indWins.size() << endl << teamWins.size();
}
