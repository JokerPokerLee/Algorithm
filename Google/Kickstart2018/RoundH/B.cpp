#include <bits/stdc++.h>

#define MP make_pair

using namespace std;

typedef pair<int, int> PII;

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	// freopen("B-small-attempt0.in", "r", stdin);
	// freopen("B-small-attempt0.out", "w", stdout);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		cout << "Case #" << tt << ": ";
		int n;
		cin >> n;
		string s;
		cin >> s;
		int l = (n + 1) / 2;
		int sum = 0, ans = 0;
		for (int i = 0, j = 0; j < n; sum -= s[i++] - '0') {
			while (j < n && j - i < l) sum += s[j++] - '0';
			ans = max(ans, sum);
		}
		cout << ans << endl;
	}
	return 0;
}