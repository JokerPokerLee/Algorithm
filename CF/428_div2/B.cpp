#include <bits/stdc++.h>

using namespace std;

int a[110];

int main() {
	freopen("1.in", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);
	int four = n, two = n * 2, one = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", &a[i]);
		int tmp = min(a[i] / 4, four);
		a[i] -= tmp * 4;
		four -= tmp;
		tmp = min(a[i] / 4, two / 2);
		a[i] -= tmp * 4;
		two -= tmp * 2;
		if (a[i] > 3) {
			printf("NO\n");
			return 0;
		}
	}
	int r1 = 0, r2 = 0, r3 = 0;
	for (int i = 0; i < k; i++) {
		switch (a[i]) {
			case 3: r3++; break;
			case 2: r2++; break;
			case 1: r1++; break;
		}
	}
	// printf("%d %d %d\n", four, two, one);
	// printf("%d %d %d\n", r3, r2, r1);
	int tmp = min(r3, four);
	four -= tmp, r3 -= tmp;
	tmp = min(r3, two / 2);
	two -= tmp * 2, r3 -= tmp;
	tmp = min(r2, two);
	two -= tmp, r2 -= tmp;
	tmp = min(r2, four);
	four -= tmp, r2 -= tmp, one += tmp;
	if (r1 + r2 * 2 + r3 * 3 > two + one + four * 2) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}
	return 0;
}