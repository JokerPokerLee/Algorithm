#include <bits/stdc++.h>

using namespace std;

bool find(int &x1, int &y1, int &x2, int &y2) {
	int l, r;
	l = x1, r = x2;
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
	if (l == x1) {
		return false;
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
	if (r == x2) {
		return false;
	}
	x2 = r + 1;
	l = y1, r = y2;
	while (l <= r) {
		int m = (l + r) / 2;
		printf("? %d %d %d %d\n", x1, m, x2, y2);
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if (x) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	if (l == y1) {
		return false;
	}
	y1 = l - 1;
	l = y1, r = y2;
	while (l <= r) {
		int m = (l + r) / 2;
		printf("? %d %d %d %d\n", x1, y1, x2, m);
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if (x) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	if (r == y2) {
		return false;
	}
	y2 = r + 1;
}

int main() {
	int n;
	scanf("%d", &n);
	int x1 = 1, y1 = 1, x2 = n, y2 = n;
	find(x1, y1, x2, y2);
	int x3, y3, x4, y4;
	if (x1 > 1) {
		x3 = 1, y3 = 1, x4 = x1 - 1, y4 = n;
		if (find(x3, y3, x4, y4)) {
			printf("! %d %d %d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3, x4, y4);
			return 0;
		}
	}
	if (y1 > 1) {
		x3 = 1, y3 = 1, x4 = n, y4 = y1 - 1;
		if (find(x3, y3, x4, y4)) {
			printf("! %d %d %d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3, x4, y4);
			return 0;
		}
	}
	if (x2 < n) {
		x3 = x2 + 1, y3 = 1, x4 = n, y4 = n;
		if (find(x3, y3, x4, y4)) {
			printf("! %d %d %d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3, x4, y4);
			return 0;
		}
	}
	if (y2 < n) {
		x3 = x2, y3 = y2 + 1, x4 = n, y4 = n;
		if (find(x3, y3, x4, y4)) {
			printf("! %d %d %d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3, x4, y4);
			return 0;
		}
	}
}