#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int l;
	cin >> l;
	string s;
	cin >> s;
	int now = 0;
	int ans = 0;
	while (now < s.size()) {
		while (now < s.size() && s[now] < 'a') {
			now++;
		}
		int nex = now;
		while (nex < s.size() && s[nex] >= 'a') {
			nex++;
		}
		set<int> cs;
		for (int i = now; i < nex; i++) {
			if (!cs.count(int(s[i]))) {
				cs.insert(int(s[i]));
			}
		}
		ans = max(ans, int(cs.size()));
		now = nex;
	}
	cout << ans << endl;
	return 0;
}