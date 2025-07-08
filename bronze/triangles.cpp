#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n; 
    cin >> n; 
    
    vector<pair<int, int>> coords(n);
    for (pair<int, int>& coord : coords) 
        cin >> coord.first >> coord.second;
    
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        auto [x1, y1] = coords[i];

        for (int k = 0; k < n; k++) {
            if (k == i) continue; 

            auto[x2, y2] = coords[k];
            if (x1 != x2 && y1 != y2) continue; 

            for (int j = 0; j < n; j++) {
                if (j == i || j == k) continue; 

                auto[x3, y3] = coords[j];
                if ((x1 == x2 && y1 == y3) || (y1 == y2 && x1 == x3)) {
                    int height = (y1 - y2) ? abs(y1 - y2) : abs(y1 - y3);
                    int base = (x1 - x2) ? abs(x1 - x2) : abs(x1 - x3); 

                    maxArea = max(maxArea, base*height);
                }
            }
        }
    }

    cout << maxArea;
}