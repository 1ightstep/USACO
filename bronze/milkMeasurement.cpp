#include <bits/stdc++.h>
using namespace std;

struct Log {
    int day; 
    string name; 
    int change;
};


int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    
    int n; 
    cin >> n;
    
    vector<Log> logs(n);
    for (Log& l : logs)
        cin >> l.day >> l.name >> l.change;
    
    sort(logs.begin(), logs.end(), [](Log a, Log b) {
        return a.day < b.day;
    });
    
    vector<string> d = {"Bessie", "Elsie", "Mildred"}; 
    unordered_map<string, int> curr;
    for (string s : d) 
        curr[s] = 7;
    int change = 0;
    for (Log l : logs) {
        curr[l.name] += l.change; 
        
        int maxCurr = 0; 
        for (auto a : curr) {
            maxCurr = max(maxCurr, a.second);
        }
        
        vector<string> nD;
        for (auto a : curr) {
            if (a.second >= maxCurr)
                nD.push_back(a.first);
        }
        
        change += nD != d; 
        d = nD;
    }
    
    cout << change;
}
