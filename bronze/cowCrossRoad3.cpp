#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int n; 
    cin >> n; 
     
    vector<pair<int, int>> cows(n);
    for (pair<int, int>& cow : cows)
        cin >> cow.first >> cow.second;

    sort(cows.begin(), cows.end());
    int cTime = 0; 
    int pTime = 0;
    for (auto [a, b] : cows) {
        if (a < pTime) {
            pTime += b;
            cTime = pTime;
        }
        else {
            cTime = a + b;
            pTime = a + b; 
        }
    }

    cout << cTime; 
}
