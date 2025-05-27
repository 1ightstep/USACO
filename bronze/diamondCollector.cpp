#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    
    int n, k; 
    cin >> n >> k;
    
    vector<int> diamonds(n);
    for (int& i : diamonds)
        cin >> i;
        
    int maxCount = 0; 
    for (int i = 0; i < n; i++) {
        int inRange = 0;
        for (int j = 0; j < n; j++) {
            if (diamonds[j] >= diamonds[i] && diamonds[j] <= diamonds[i] + k)
                inRange ++;
        }
        maxCount = max(inRange, maxCount);
    }
    
    cout << maxCount;
}
