#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n; 
    
    vector<int> f(n);
    for (int &i : f)
        cin >> i;
        
    int count = n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j ++) {
            vector<int> temp;
            double average = 0;
            
            for (int k = i; k <= j; k++) {
                temp.push_back(f[k]);
                average += f[k];
            }
            average /= (j - i) + 1; 
            
            for (int k : temp) {
                if (k == average) {
                    count ++; 
                    break;
                }
            }
        }
    }
    
    cout << count;
}
