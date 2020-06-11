#include <bits/stdc++.h>

using namespace std;

int divide(int l, int r, int b, vector<string> &words) {
	// cout << l << " " << r << endl;
	if (r == l + 1) return 0;
	int s = l, t = l;
	int rem = 0, res = 0;
	while (s < r) {
		if (b >= words[s].size()) {
			s++;
			continue;
		}
		t = s + 1;
		while (t < r && b < words[t].size() && words[t][b] == words[s][b]) t++;
		// cout << s << "-" << t << endl;
		int tmp = divide(s, t, b + 1, words);
		res += tmp;
		if (tmp + 2 <= t - s) {
			res += 2;
		}
		s = t;
	}
	return res;
}

int main() {
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		int n;
		cin >> n;
		vector<string> words;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			reverse(s.begin(), s.end());
			words.push_back(s);
		}
		sort(words.begin(), words.end());
		int ans = divide(0, n, 0, words);
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}