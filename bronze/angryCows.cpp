#include <bits/stdc++.h>
using namespace std;

void explode(vector<int>& hay, int& counter, int dir, int t, int index) {
    int nextIndex = index;
    while (true) {
        int candidate = nextIndex + dir;
        if (candidate < 0 || candidate >= hay.size()) break;
        if (abs(hay[index] - hay[candidate]) > t) break; 
        nextIndex = candidate; 
        counter ++;
    }
    if (nextIndex != index) {
        explode(hay, counter, dir, t + 1, nextIndex);
    }
    
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n; 
    cin >> n; 

    vector<int> hay(n);
    for (int& i : hay) 
        cin >> i; 
    sort(hay.begin(), hay.end());

    int maxCount = INT32_MIN;
    for (int i = 0; i < hay.size(); i++) {
        int currCount = 1;
        explode(hay, currCount, 1, 1, i);
        explode(hay, currCount, -1, 1, i);
        maxCount = max(maxCount, currCount);
    }

    cout << maxCount;
}