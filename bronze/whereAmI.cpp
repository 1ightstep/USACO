#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n; 
    cin >> n; 
    
    string boxes; 
    cin >> boxes; 
    
    for (int i = 1; i < n; i++) {
        unordered_map<string, int> freq;
        bool isSolution = true;
        for (int j = 0; j <= n - i; j++) {
            string subStr = boxes.substr(j, i);
            freq[subStr] ++;
            if (freq[subStr] > 1) isSolution = false;
        }
        if (isSolution) {
            cout << i;
            break;
        }
    }
}
