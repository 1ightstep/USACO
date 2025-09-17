#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    
    int n; 
    cin >> n; 

    string a;
    string b;
    cin >> a; 
    cin >> b; 
    
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            while (a[i] != b[i]) {
                i++;
            }
            count ++;
        }
    }

    cout << count;
}
