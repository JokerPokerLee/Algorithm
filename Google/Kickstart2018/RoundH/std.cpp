#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T>
void prvec(vector<T>& v) {
	for (T n: v) cout << n << " ";
	cout << "\n";
}

const int MAXN = 55;
const int MAXP = 105;
int len[MAXP];
bool valid[MAXP];
int forbid[MAXP][MAXN];
int N, P;

int main() {
	freopen("1.in", "r", stdin);
	freopen("std.out", "w", stdout);
	// freopen("./input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tcnt = 1; tcnt <= T; tcnt++) {
		memset(len, 0, sizeof(len));
		memset(valid, false, sizeof(valid));
		memset(forbid, 0, sizeof(forbid));
		
		cin >> N >> P;
		for (int i = 0; i < P; i++) {
			string s;
			cin >> s;
			len[i] = s.length();
			valid[i] = true;
			for (int j = 0; j < len[i]; j++) {
				forbid[i][j] = (s[j] == 'R' ? 0 : 1);
			}
		}
		for (int i = 0; i < P; i++) {
			for (int j = 0; j < P; j++) {
				// forbid[i] is the prefix of forbid[j]
				if (i == j || len[i] > len[j]) {
					continue;
				}
				bool isprefix = true;
				for (int k = 0; k < len[i]; k++) {
					if (forbid[i][k] != forbid[j][k]) {
						isprefix = false;
						break;
					}
				}
				if (isprefix) {
					valid[j] = false;
				}
			}
		}
		ll ans = (ll)1 << N;
		for (int i = 0; i < P; i++) {
			if (valid[i]) {
				ans -= ((ll)1 << (N - len[i]));
			}
		}			
		
		cout << "Case #" << tcnt << ": ";
		cout << ans << endl;
	}	
	return 0;
}