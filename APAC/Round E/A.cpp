#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	// freopen("A-small-attempt0.in", "r", stdin);
	// freopen("A-small-attempt0.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		string pat;
		cin >> pat;
		long long l, r;
		cin >> l >> r;
		long long tot = 0;
		for (int i = 0; i < pat.size(); i++) {
			if (pat[i] == 'B') {
				tot++;
			}
		}
		// cout << tot << endl;
		long long cnt = 0;
		if (l % pat.size() != 1) {
			for (int i = (l - 1) % pat.size(); i < pat.size(); i++) {
				if (pat[i] == 'B') {
					cnt++;
				}
			}
		}
		// cout << cnt << endl;
		if (r % pat.size()) {
			for (int i = 0; i < r % pat.size(); i++) {
				if (pat[i] == 'B') {
					cnt++;
				}
			}
		}
		// cout << cnt << endl;
		cnt += ((r / pat.size()) - ((l - 1) / pat.size()) - ((l % pat.size() == 1) ? 0 : 1)) * tot;;
		cout << "Case #" << tt << ": " << cnt << endl;
	}
	return 0;
}