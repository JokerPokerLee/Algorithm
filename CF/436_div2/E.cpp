#include <bits/stdc++.h>

#define N 110
#define M 2020

using namespace std;

int f[M], s[N][M];

struct Item{
	int t, d, p, num;
	Item(int t, int d, int p, int n) : t(t), d(d), p(p), num(n) {}
};

bool cmp(Item a, Item b) {
	return a.d > b.d;
}

int main() {
	freopen("1.in", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<Item> w;
	int m = 0;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		w.push_back(Item(x, y, z, i + 1));
		m = max(m, w[i].d);
	}
	sort(w.begin(), w.end(), cmp);
	for (int i = 0; i < n; i++) {
		int ddl = w[i].d - w[i].t;
		int lar = 0;
		for (int j = 0; j <= m; j++) {
			if (j < ddl && f[j + w[i].t] + w[i].p > f[j]) {
				f[j] = f[j + w[i].t] + w[i].p;
				s[i][j] = i + 1;
			} else {
				s[i][j] = 0;
			}
		}
	}
	printf("%d\n", f[0]);
	vector<int> seq;
	int i = n, j = 0;
	while (--i >= 0) {
		if (s[i][j] > 0) {
			seq.push_back(w[s[i][j] - 1].num);
			j += w[s[i][j] - 1].t;
		}
	}
	printf("%d\n", int(seq.size()));
	for (int i = 0; i < seq.size(); i++) {
		printf("%d%c", seq[i], " \n"[i == seq.size() - 1]);
	}
	return 0;
}