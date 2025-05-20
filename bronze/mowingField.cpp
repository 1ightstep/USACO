#include <bits/stdc++.h>
using namespace std; 

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int n; 
    cin >> n; 

    vector<char> dir(n);
    vector<int> dis(n);
    for (int i = 0; i < n; i++)
        cin >> dir[i] >> dis[i];
        
    pair<int, int> curr = {0, 0};
    pair<int, int> change = {0, 0};
    map<pair<int, int>, int> coords = {{curr, 0}};
    int currT = 0;
    int minX = INT32_MAX;

    for (int i = 0; i < n; i++) {
        switch(dir[i]) {
            case 'N':
                change = {0, 1};
                break;
            case 'E':
                change = {1, 0};
                break;
            case 'S':
                change = {0, -1};
                break;
            case 'W':
                change = {-1, 0};
                break;
        }
        for (int j = 0; j < dis[i]; j++) {
            curr.first += change.first; 
            curr.second += change.second;
            currT ++;
            if (coords.count(curr) != 0) {
                minX = min(minX, currT - coords[curr]);
            }
            coords[curr] = currT;
        }
    }

    int min = minX == INT32_MAX ? -1 : minX;
    cout << min;
}