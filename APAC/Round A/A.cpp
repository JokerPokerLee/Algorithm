#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("1.in", "r", stdin);
	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		int n;
		cin >> n;
		cin.ignore();
		priority_queue< pair<int , string> , vector< pair<int , string> > , greater<>> pn;
		for (int i = 0; i < n; i++) {
			string name;
			getline(cin, name);
			int* cnt = new int[26];
			memset(cnt, 0, sizeof(int) * 26);
			int tot = 0;
			for (int j = 0; j < name.size(); j++) {
				if (isalpha(name[j]) && !cnt[name[j] - 'A']) {
					tot++;
				}
				if (isalpha(name[j])) {
					cnt[name[j] - 'A']++;
				}
			}
			delete cnt;
			pn.push(make_pair(50 - tot, name));
		}
		cout << "Case #" << tt << ": " << pn.top().second << endl;
	}
	return 0;
}