#include <bits/stdc++.h>

using namespace std;

int a[30][30];
int stdd[30];

int main() {
	freopen("1.in", "r", stdin);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		stdd[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			swap(stdd[i], stdd[j]);
			bool flag = true;
			for (int g = 1; g <= n; g++) {
				int cnt = 0;
				for (int h = 1; h <= m; h++) {
					if (a[g][h] != stdd[h]) {
						cnt++;
					}
				}
				if (cnt != 2 && cnt != 0) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << "YES" << endl;
				return 0;
			}
			swap(stdd[i], stdd[j]);
		}
	}
	cout << "NO" << endl;
	return 0;
}