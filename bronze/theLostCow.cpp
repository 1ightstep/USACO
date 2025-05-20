#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    
    int x, y; 
    cin >> x >> y;
    vector<int> d;
    int total = 0, i = 1, alter = 1;
    while (abs(i*alter + x) < abs(y)) {
        d.push_back(x + alter*i);
        alter *= -1;
        i *= 2; 
    }
    d.push_back(x + alter*i);
    for (int i = 0; i < d.size()-1; i++)
        total += abs(d[i] - d[i+1]);
    cout << total << "\n";
}