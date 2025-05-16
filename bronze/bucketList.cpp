#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    
    int n; 
    cin >> n;
    
    vector<int> s(n), t(n), b(n);
    for (int i = 0; i < n; i++) cin >> s[i] >> t[i] >> b[i];
    
    int start = *min_element(s.begin(), s.end());
    int end = *max_element(t.begin(), t.end());
    int buckAvail = 0, buckNeed = 0; 
    for (int i = 0; i < end - start; i++) {
        for (int j = 0; j < n; j++) {
            if (t[j] == i)
                buckAvail += b[j];
            if (s[j] == i && b[j] > buckAvail)
                buckNeed += b[j] - buckAvail;
            if (s[j] == i) 
                buckAvail -= min(buckAvail, b[j]);
        }
    }
  
    cout << buckNeed;
}
