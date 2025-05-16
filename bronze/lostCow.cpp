#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);

	int x, y;
	cin >> x >> y;
	
	int dis = 1, dir = 1, total = 0;

	while ((x < y && x + dis*dir < y) || (x > y && x + dis*dir > y)) {
		total += dis * 2;
		dis *= 2;
		dir *= -1;
	}
	
	total += abs(x - y);
	cout << total;
}
