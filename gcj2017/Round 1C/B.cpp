#include <bits/stdc++.h>

#define PII pair<int, int>
#define MP make_pair

using namespace std;

int solve(vector<PII> ac, vector<PII> aj) {
	// cout << "round" << endl;
	vector<int> inv;
	int n = ac.size();
	int m = aj.size();
	for (int i = 0; i < n- 1; i++) {
		bool flag = true;
		for (int j = 0; j < m; j++) {
			if (aj[j].first > ac[i].first && aj[j].first < ac[i + 1].first) {
				flag = false;
				break;
			}
		}
		if (flag) {
			inv.push_back(ac[i + 1].first - ac[i].second);
		}
	}
	if (!m || aj[0].first > ac[0].first && aj[m - 1].first < ac[n - 1].first) {
		inv.push_back(1440 - ac[n - 1].second + ac[0].first);
	}
	sort(inv.begin(), inv.end());
	int tot = 0;
	for (int i = 0; i < n; i++) {
		tot += ac[i].second - ac[i].first;
	}
	// cout << tot << endl;
	int ans = ac.size() * 2;
	for (int i = 0; i < inv.size(); i++) {
		// cout << inv[i] << endl;
		if (tot + inv[i] > 720) {
			break;
		}
		tot += inv[i];
		ans -= 2;
	}
	return ans;
}

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	// freopen("B-small-attempt0.in", "r", stdin);
	// freopen("B-small-attempt0.out", "w", stdout);
	// freopen("B-large.in", "r", stdin);
	// freopen("B-large.out", "w", stdout);
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++) {
		printf("Case #%d: ", tt);
		// cout << endl;
		int n, m;
		scanf("%d %d", &n, &m);
		if (!n && !m) {
			printf("2\n");
			continue;
		}
		vector<PII> ac, aj;
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			ac.push_back(MP(x, y));
		}
		sort(ac.begin(), ac.end());
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			aj.push_back(MP(x, y));
		}
		sort(aj.begin(), aj.end());
		if (!n) {
			swap(ac, aj);
			swap(n, m);
		}
		int ans = solve(ac, aj);
		if (m) {
			ans = max(ans, solve(aj, ac));
		}
		printf("%d\n", ans);
	}
	return 0;
}