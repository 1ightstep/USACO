#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("mixmilk.in", "r", stdin);
    
    vector<int> capacity(3);
    vector<int> milk(3);
    for (int i = 0; i < 3; i++) 
        scanf("%d %d", &capacity[i], &milk[i]);
    
    int a, b, amt;
    for (int i = 0; i < 100; i++) {
        a = i % 3; 
        b = (i+1) % 3;
        amt = min({milk[a], capacity[b] - milk[b]});
        
        milk[a] -= amt; 
        milk[b] += amt;
    }
    
    freopen("mixmilk.out", "w", stdout);
    for (int i : milk) 
        printf("%d\n", i);
}
