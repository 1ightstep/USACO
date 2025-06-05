#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;

    //somehow using lambda to sort gets questions wrong :<
    vector<pair<int, char>> cows(n);
    for (auto& cow : cows)
        cin >> cow.second >> cow.first;

    sort(cows.begin(), cows.end());

    vector<int> left(n), right(n); 
    for (int i = 1; i < n; i++) {
        left[i] += left[i - 1];
        if (cows[i - 1].second == 'L')
            left[i] ++;
    }

    for (int i = n - 2; i >= 0; i--) {
        right[i] += right[i + 1];
        if (cows[i + 1].second == 'G')
            right[i] ++;
    }

    int minCows = n;
    for (int i = 0; i < n; i++) {
        minCows = min(minCows, left[i] + right[i]);
    }

    cout << minCows;
}
