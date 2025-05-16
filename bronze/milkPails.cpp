#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m; 
    cin >> x >> y >> m;

    int max = 0;
    int curr;
    for (int i = 0; i <= m / x; i++) {
        curr =  i*x + (m - i*x)/y*y;
        if (curr <= m && curr > max) 
            max = curr; 
    }
    cout << max;
}