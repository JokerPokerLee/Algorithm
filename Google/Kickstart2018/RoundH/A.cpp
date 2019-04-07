#include <bits/stdc++.h>

#define MP make_pair

using namespace std;

typedef pair<int, int> PII;

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	// freopen("A-small-attempt1.in", "r", stdin);
	// freopen("A-small-attempt1.out", "w", stdout);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		cout << "Case #" << tt << ": ";
		int n, k;
		cin >> n >> k;
		// cout << n << " " << k << endl;
		vector<string> forb;
		for (int i = 0; i < k; i++) {
			string s;
			cin >> s;
			forb.push_back(s);
		}
		sort(forb.begin(), forb.end());
		string pre = "0";
		long long ans = 1LL << n;
		// cout << ans << endl;
		for (int i = 0; i < k; i++) {
			if (forb[i].find(pre) == 0) {
				continue;
			}
			pre = forb[i];
			ans -= 1LL << (n - pre.size());
			// cout << ans << endl;
		}
		cout << ans << endl;
	}
	return 0;
}