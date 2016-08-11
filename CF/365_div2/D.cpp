#include <cstdio>
#include <vector>
#include <map>

#define N 1000100

using namespace std;

int a[N], c[N], s[N], res[N];
vector< pair<int , int> > q[N];
map<int , int> last;
int n, m;

void add(int pos, int val) {
	while (pos <= n) {
		c[pos] ^= val;
		pos += pos & (-pos);
	}
}

int sum(int pos) {
	int res = 0;
	while (pos) {
		res ^= c[pos];
		pos -= pos & (-pos);
	}
	return res;
}

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] ^ a[i];
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		q[r].push_back(make_pair(l, i));
	}
	for (int r = 1; r <= n; r++) {
		if (last.count(a[r])) {
			// cout << "!" << endl;
			add(last[a[r]], a[r]);
			last[a[r]] = r;
			add(r, a[r]);
		} else {
			last[a[r]] = r;
			add(r, a[r]);
		}
		for (int j = 0; j < q[r].size(); j++) {
			int l = q[r][j].first;
			int k = q[r][j].second;
			res[k] = s[r] ^ s[l - 1] ^ sum(r) ^ sum(l - 1);
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%d\n", res[i]);
	}
	return 0;
}