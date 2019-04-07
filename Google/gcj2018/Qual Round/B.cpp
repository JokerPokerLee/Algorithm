#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		cout << "Case #" << tt << ": ";
		int n;
		scanf("%d", &n);
		vector<int> p[2];
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			p[i & 1].push_back(x);
		}
		sort(p[0].begin(), p[0].end());
		sort(p[1].begin(), p[1].end());
		bool flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (p[i & 1][i >> 1] > p[(i + 1) & 1][(i + 1) >> 1]) {
				cout << i << endl;
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "OK" << endl;	
		}
	}
	return 0;
}