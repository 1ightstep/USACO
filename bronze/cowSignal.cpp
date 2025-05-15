#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "a", stdout);
    
    int m, n, k;
    cin >> m >> n >> k;
    vector<string> split(m);
    
    for (int i = 0; i < m; i++) cin >> split[i];
    
    for (int i = 0; i < m*k; i++) {
        for (int j = 0; j < n*k; j++)
            cout << split[i/k][j/k]; 
        cout << "\n";
    }
}
