#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		char cake[1010];
		int k;
		scanf("%s%d", cake, &k);
		int l = strlen(cake);
		int ans = 0;
		for (int i = 0; i <= l - k; i++) {
			if (cake[i] == '-') {
				ans++;
				for (int j = 0; j < k; j++) {
					cake[i + j] = '+' + '-' - cake[i + j];
				}
			}
		}
		bool flag = false;
		for (int i = l - k; i < l; i++) {
			if (cake[i] == '-') {
				flag = true;
				break;
			}
		}
		printf("Case #%d: ", tt);
		if (flag) {
			printf("IMPOSSIBLE\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}