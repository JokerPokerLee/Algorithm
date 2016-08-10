#include <bits/stdc++.h>

using namespace std;

vector<int> msg;
int head[300300], tail[300300], nex[300300];

int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		head[i] = tail[i] = -1;
	}
	int cnt = 0;
	int fon = 0;
	while (q--) {
		int ty, x;
		cin >> ty >> x;
		if (ty == 1) {
			if (tail[x] != -1) {
				nex[tail[x]] = msg.size();
			} else {
				head[x] = msg.size();
			}
			tail[x] = msg.size();
			msg.push_back(x);
			cnt++;
			cout << cnt << endl;
		}
		if (ty == 2) {
			while (head[x] < tail[x]) {
				head[x] = nex[head[x]];
				cnt--;
			}
			if (tail[x] != -1)
				cnt--;
			tail[x] = -1;
			cout << cnt << endl;
		}
		if (ty == 3) {
			while (fon < x) {
				if (fon >= head[msg[fon]] && tail[msg[fon]] != -1) {
					if (head[msg[fon]] == tail[msg[fon]])
						tail[msg[fon]] = -1;
					else
						head[msg[fon]] = nex[fon];
					cnt--;
				}
				fon++;
			}
			cout << cnt << endl;
		}
	}
	return 0;
}