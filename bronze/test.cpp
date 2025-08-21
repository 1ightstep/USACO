#include <bits/stdc++.h>
using namespace std;

int main() {
    int m = 3; 
    for (int b = 0; b < (1 << m); b++) {
        vector<int> subset;
        for (int i = 0; i < m; i++) {
            if (b & (1 << i)) subset.push_back(i);
        }
                    for (int i : subset) cout << i << "|";
            cout << endl;
    }
}