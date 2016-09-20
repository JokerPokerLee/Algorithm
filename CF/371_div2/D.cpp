#include <bits/stdc++.h>

using namespace std;

void find(int &x1, int &y1, int &x2, int &y2) {
	int l = x1, r = x2;
	while (l <= r) {
		int m = (l + r) / 2;
		printf("? %d %d %d %d\n", m, y1, x2, y2);
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if (x) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	x1 = l - 1;
	l = x1, r = x2;
	while (l <= r) {
		int m = (l + r) / 2;
		printf("? %d %d %d %d\n", x1, y1, m, y2);
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if (x) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	x2 = r + 1;
}

int main() {
	int n;
	scanf("%d", &n);
	int x1 = 0, y1 = 0, x2 = n, y2 = n;
	find(x1, y1, x2, y2);
}