#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    string whole, remove, result = ""; 
    cin >> whole >> remove;

    for (char c : whole) {
        result += c; 
        if (result.length() >= remove.length() && result.substr(result.length()-remove.length(), remove.length()) == remove) {
            result.erase(result.length()-remove.length(), remove.length());
        }
    }

    cout << result;
}