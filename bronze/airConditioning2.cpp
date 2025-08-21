#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; 

    vector<vector<int>> cows(n, vector<int>(3));
    int maxT = INT32_MIN; 
    for (vector<int>& cow : cows) {
        cin >> cow[0] >> cow[1] >> cow[2];
        maxT = max(maxT, cow[1]);
    }
    
    vector<vector<int>> conds(m, vector<int>(4));
    for (vector<int>& cond : conds)
        cin >> cond[0] >> cond[1] >> cond[2] >> cond[3];

    vector<int> stalls(maxT + 1);
    for (vector<int>& cow : cows) {
        for (int i = cow[0]; i <= cow[1]; i++) {
            stalls[i] += cow[2];
        }
    }
    
    int minCost = INT32_MAX;
    for (int i = 0; i < (1 << m); i++) {
        vector<vector<int>> subset; 
        vector<int> copy = stalls;
        int currCost = 0;
        for (int k = 0; k < m; k++) {
            if (i & (1<<k)) subset.push_back(conds[k]);
        }

        for (vector<int> cond : subset) {
            for (int k = cond[0]; k <= cond[1]; k++) {
                copy[k] -= cond[2];
            }
            currCost += cond[3];
        }
        
        bool satisfy = true;
        for (int k : copy) {
            if (k > 0) {
                satisfy = false;
                break;
            }
        }
        
        minCost = satisfy ? min(minCost, currCost) : minCost;
    }

    cout << minCost;
}