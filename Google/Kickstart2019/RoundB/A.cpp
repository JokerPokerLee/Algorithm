#include <bits/stdc++.h>

using namespace std;

int main() {
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		cout << "Case #" << tt << ": ";
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		vector<vector<int>> cnt(n + 1);
		cnt[0] = vector<int>(26, 0);
		for (int i = 0; i < n; i++) {
			cnt[i + 1] = vector<int>(26, 0);
			for (int j = 0; j < 26; j++) {
				cnt[i + 1][j] = cnt[i][j];
			}
			cnt[i + 1][s[i] - 'A']++;
		}
		int ans = 0;
		while (q--) {
			int l, r;
			cin >> l >> r;
			l--;
			int odd = 0;
			for (int i = 0; i < 26; i++) {
				if (cnt[r][i] - cnt[l][i] & 1) {
					odd += 1;
				}
			}
			if (odd < 2) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}