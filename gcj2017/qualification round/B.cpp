#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("B-small-attempt0.in", "r", stdin);
	// freopen("B-small-attempt0.out", "w", stdout);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		char num[30];
		scanf("%s", num);
		int l = strlen(num);
		int i;
		for (i = 0; i < l - 1; i++) {
			if (num[i] > num[i + 1]) {
				break;
			}
		}
		printf("Case #%d: ", tt);
		if (i == l - 1) {
			printf("%s\n", num);
			continue;
		}
		while (i) {
			if (num[i] == num[i - 1]) {
				i--;
			} else {
				break;
			}
		}
		num[i] -= 1;
		for (int j = i + 1; j < l; j++) {
			num[j] = '9';
		}
		printf("%s\n", num[0] == '0' ? num + 1 : num);
	}
	return 0;
}