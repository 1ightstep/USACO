#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; 
    cin >> n;
    
    vector<int> c(n);
    for (int& i : c) 
        cin >> i; 
    sort(c.begin(), c.end());

    int cost;
    long long max = LONG_LONG_MIN;
    for (int i = 0; i < c.size(); i++) {
        long long curr = c[i] * (c.size() - i);
        if (curr > max) {
            cost = c[i];
            max = curr;
        }
    }

    cout << max << " " << cost;
}