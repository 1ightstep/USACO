#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n; 
    cin >> n; 

    string a, b; 
    vector<int> amtA(26), amtB(26), ans(26);

    for (int i = 0; i < n; i++) {
        cin >> a >> b; 
        for (int j = 0; j < a.size(); j++) 
            amtA[a[j] - 97] ++;
        for (int j = 0; j < b.size(); j++) 
            amtB[b[j] - 97] ++;
        for (int j = 0; j < 26; j++)
            ans[j] += max(amtA[j], amtB[j]);
        
        fill(amtA.begin(), amtA.end(), 0);
        fill(amtB.begin(), amtB.end(), 0);
    }
    
    for (int i : ans)
        cout << i << "\n";
}