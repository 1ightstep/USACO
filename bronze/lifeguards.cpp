#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n; 
    cin >> n; 
    
    vector<int> tl(1000);
    vector<pair<int, int>> guards(n);
    for (pair<int, int>& guard : guards) {
        cin >> guard.first >> guard.second; 
        for (int i = guard.first; i < guard.second; i++) {
            tl[i]++; 
        }
    }

    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        for (int k = guards[i].first; k < guards[i].second; k++)
            tl[k]--;

        int currSum = 0;
        for (int k = 0; k < 1000; k++) {
            if (tl[k] > 0)
                currSum++;
        }
        maxSum = max(maxSum, currSum);

        for (int k = guards[i].first; k < guards[i].second; k++)
            tl[k]++;

    }

    cout << maxSum;
}