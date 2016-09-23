#include <bits/stdc++.h>

#define N 100100
#define SI N * 6
#define MOD 1000000007

using namespace std;

struct Mat {
	int m[2][2];
	Mat() {
		memset(m, 0, sizeof(m));
	}
	int* operator [] (int x) {
		return m[x];
	}
	Mat operator + (Mat a) {
		Mat res = Mat();
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				res[i][j] = (m[i][j] + a[i][j]) % MOD;
			}
		}
		return res;
	}
	Mat operator * (Mat a) {
		Mat res = Mat();
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					res[i][j] = (res[i][j] + 1LL * m[i][k] * a[k][j] % MOD) % MOD;
				}
			}
		}
		return res;
	}
	void print() {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				printf("%d%c", m[i][j], " \n"[j == 2]);
			}
		}
	}
} mat[SI], Unit, T0, M[50];

long long lazy[SI], a[N], z;
int s, t;

void InitMat() {
	Unit[0][0] = Unit[1][1] = 1;
	T0[0][1] = T0[1][0] = T0[1][1] = 1;
	M[1] = T0;
	for (int i = 2; i < 50; i++) {
		M[i] = M[i - 1] * M[i - 1];
	}
}

Mat power(long long x) {
	Mat res = Unit;
	int k = 1;
	while (x) {
		if (x & 1) {
			res = res * M[k];
		}
		k++;
		x >>= 1;
	}
	return res;
}

void init(int be, int en, int now) {
	if (be == en) {
		mat[now] = power(a[be]);
		return;
	}
	int mid = (be + en) / 2;
	init(be, mid, now << 1);
	init(mid + 1, en, (now << 1) + 1);
	mat[now] = mat[now << 1] + mat[(now << 1) + 1];
}

inline void push(int now) {
	int l = now << 1, r = l + 1;
	lazy[l] += lazy[now];
	lazy[r] += lazy[now];
	mat[l] = mat[l] * power(lazy[now]);
	mat[r] = mat[r] * power(lazy[now]);
	lazy[now] = 0;
}

void mul(int be, int en, int now) {
	if (s <= be && en <= t) {
		mat[now] = mat[now] * power(z);
		lazy[now] += z;
		return;
	}
	if (lazy[now]) push(now);
	int mid = (be + en) / 2;
	int l = now << 1, r = l + 1;
	if (s <= mid) mul(be, mid, l);
	if (t > mid) mul(mid + 1, en, r);
	mat[now] = mat[l] + mat[r];
}

Mat calc(int be, int en, int now) {
	if (s <= be && en <= t) {
		return mat[now];
	}
	if (lazy[now]) push(now);
	Mat res;
	int mid = (be + en) / 2;
	int l = now << 1, r = l + 1;
	if (s <= mid) res = res + calc(be, mid, l);
	if (t > mid) res = res + calc(mid + 1, en, r);
	mat[now] = mat[l] + mat[r];
	return res;
}

void print(int be, int en, int now) {
	printf("======%d : (%d, %d)======\n", now, be, en);
	mat[now].print();
	if (be == en) return;
	int mid = (be + en) / 2;
	int l = now << 1, r = l + 1;
	print(be, mid, l);
	print(mid + 1, en, r);
}

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	InitMat();
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	init(1, n, 1);
	// print(1, n, 1);
	for (int i = 0; i < m; i++) {
		int ty, l, r;
		scanf("%d %d %d", &ty, &l, &r);
		s = l, t = r;
		if (ty == 1) {
			long long x;
			scanf("%lld", &x);
			z = x;
			mul(1, n, 1);
		} else {
			Mat res = calc(1, n, 1);
			cout << res[1][0] << endl;
		}
	}
	return 0;
}