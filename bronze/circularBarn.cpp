#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    
    int n; 
    cin >> n; 

    vector<int> rooms(n);
    for (int i = 0; i < n; i++) 
        cin >> rooms[i];
        
    int currDist = 0;
    int distMin = INT32_MAX; 
    for (int i = 0; i < n; i++) {
        currDist = 0;
        for (int j = 0; j < n; j++) {
            currDist += rooms[(i + j) % n] * j;
        }
        distMin = min(distMin, currDist);
    }
    cout << distMin;
}
