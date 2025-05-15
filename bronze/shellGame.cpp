#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("shell.in", "r", stdin);

    int passes;
    scanf("%d", &passes);

    vector<int> simulation = {0, 1, 2}; 
    vector<int> counter(3);
    int a, b, g;

    for (int i = 0; i < passes; i++) {
        scanf("%d %d %d", &a, &b, &g);
        a --; b --; g --;

        swap(simulation[a], simulation[b]);
        counter[simulation[g]] ++;
    }

    freopen("shell.out", "w", stdout);
    printf("%d", max({counter[0], counter[1], counter[2]}));
}