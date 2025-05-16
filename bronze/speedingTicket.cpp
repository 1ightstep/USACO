#include <bits/stdc++.h>
using namespace std; 

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    
    
    vector<pair<int, int>> road(n);
    vector<pair<int, int>> bess(m); 

    for (int i = 0; i < n; i++) cin >> road[i].first >> road[i].second;
    for (int i = 0; i < m; i++) cin >> bess[i].first >> bess[i].second;
    
    int best = 0, j = 0, i = 0, len = 0;
    while (i <  n && j < m) {
        len = min(road[i].first, bess[j].first);
        road[i].first -= len;
        bess[j].first -= len; 
        best = max(best, bess[j].second - road[i].second);

        if (!road[i].first) i ++;
        if (!bess[j].first) j++;
        
    }
    cout << best;
}