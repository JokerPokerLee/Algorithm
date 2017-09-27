#include <bits/stdc++.h>

using namespace std;

bool vol[27];

int main() {
	freopen("1.in", "r", stdin);
	vol['a' - 'a'] = true;
	vol['e' - 'a'] = true;
	vol['i' - 'a'] = true;
	vol['o' - 'a'] = true;
	vol['u' - 'a'] = true;
	string s;
	cin >> s;
	// cout << s << endl;
	string ans = "";
	int l = 0;
	while (l < s.size()) {
		int pre = l;
		while (l < s.size() && vol[s[l] - 'a']) {
			l++;
		}
		ans += s.substr(pre, l - pre);
		// cout << l << endl;
		// cout << ans << endl;
		int r = l;
		while (r < s.size() && !vol[s[r] - 'a']) {
			r++;
		}
		// cout << l << " " << r << endl;
		int cnt = 0;
		int now = l;
		string tmp = "";
		while (now < r) {
			int nex = now;
			while (nex < r && s[now] == s[nex]) {
				nex++;
			}
			// cout << now << " " << nex << endl;
			if (nex - now > 1) {
				tmp += ' ';
				cnt = 0;
			} else {
				if (cnt == 1) {
					cnt++;
				} else {
					tmp += ' ';
					cnt = (cnt + 1) % 2;
				}
			}
			tmp += s.substr(now, nex - now);
			now = nex;
			// cout << ans << endl;
		}
		if (tmp.size() > 0) {
			ans += tmp.substr(1);
		}
		l = r;
	}
	cout << ans << endl;
	return 0;
}