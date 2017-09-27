#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);
	int saved = 0, gived = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		saved += x;
		int tmp = min(saved, 8);
		gived += tmp;
		saved -= tmp;
		if (gived >= k) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}