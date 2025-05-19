#include <bits/stdc++.h>
using namespace std; 

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    
    int n;
    cin >> n; 
    
    vector<string> ramp(n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> ramp[i] >> a[i] >> b[i];
    
    vector<int> before = {INT16_MIN, INT16_MAX};
    vector<int> after = {INT16_MIN, INT16_MAX};
    
    for (int i = n - 1; i >= 0; i--) {
        if (ramp[i] == "on") {
            before[0] -= b[i]; 
            before[1] -= a[i];
        }
        else if (ramp[i] == "off") {
            before[0] += a[i]; 
            before[1] += b[i];
        }
        else if (ramp[i] == "none") {
            before[0] = max(a[i], before[0]);
            before[1] = min(b[i], before[1]);
        }
    }
    cout << max(0, before[0]) << " " << max(0, before[1]) << "\n";
    
    for (int i = 0; i < n; i++) {
        if (ramp[i] == "on") {
            after[0] += a[i]; 
            after[1] += b[i];
        }
        else if (ramp[i] == "off") {
            after[0] -= b[i]; 
            after[1] -= a[i];
        }
        else if (ramp[i] == "none") {
            after[0] = max(a[i], after[0]);
            after[1] = min(b[i], after[1]);
        }
    }
    cout << max(0, after[0]) << " " << max(0, after[1]);
}
