#include <bits/stdc++.h>

using namespace std;

int main() {
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		cout << "Case #" << tt << ": ";
		int n, s, x, e;
		cin >> n >> s;
		vector<map<int, int>> cnt(n + 1);
		for (int i = 0; i < n; i++) {
			for (auto &p: cnt[i]) {
				e = p.first;
				cnt[i + 1][e] = cnt[i][e];
			}
			cin >> x;
			if (!cnt[i + 1].count(x)) {
				cnt[i + 1][x] = 0;
			}
			cnt[i + 1][x]++;
		}
		int ans = 1;
		for (int i = 1; i < n; i++) {
			for (int j = n; j > i; j--) {
				int tmp = j - i + 1;
				if (tmp <= ans) break;
				for (auto &p: cnt[j]) {
					e = p.first;
					if (cnt[j][e] - cnt[i - 1][e] > s) {
						tmp -= cnt[j][e] - cnt[i - 1][e];
					}
				}
				ans = max(tmp, ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}