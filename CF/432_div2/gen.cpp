#include <bits/stdc++.h>

using namespace std;

int p[1000010], a[1000010];
int idx[1000010];
bool ex[1000010];
int tot;

int main() {
	freopen("1.in", "w", stdout);
	for (int i = 1; i <= 1000000; i++) {
		a[i] = i;
	}
	for (int i = 2; i <= 1000000; i++) {
		if (a[i] == i) {
			idx[i] = tot;
			p[tot++] = i;
		}
		for (int j = 0; j < tot; j++) {
			if (1LL * p[j] * i > 1000000) {
				break;
			}
			a[p[j] * i] = p[j];
			if (i % p[j] == 0) {
				break;
			}
		}
	}
	int n = 80000, x = 999999999, y = 987654321;
	printf("%d %d %d\n", n, x, y);
	for (int i = 0; i < n; i++) {
		if (i < tot) {
			x = p[i];
		} else {
			x = rand() % 1000000;
		}
		printf("%d\n", x);
	}
	return 0;
}