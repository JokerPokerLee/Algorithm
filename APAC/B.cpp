#include <bits/stdc++.h>

#define MP make_pair

using namespace std;

vector<long long> rb[100100];

long long mul(long long x, long long y, long long mo) {
	long long r = 1;
	long long z = x;
	while (y) {
		if (y & 1) {
			r = r * z % mo;
		}
		z = z * z % mo;
		y >>= 1;
	}
	return r;
}

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	// freopen("B-small-attempt2.in", "r", stdin);
	// freopen("B-small-attempt2.out", "w", stdout);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		long long A, B, N, K;
		cin >> A >> B >> N >> K;
		// long long ans = 0;
		// for (long long i = 1; i <= N; i++) {
		// 	for (long long j = 1; j <= N; j++) {
		// 		if (i != j) {
		// 			if ((mul(i, A, K) + mul(j, B, K)) % K == 0) {
		// 				ans++;
		// 			}
		// 		}
		// 	}
		// }
		for (int i = 0; i < K; i++) {
			rb[i].clear();
		}
		for (int i = 0; i < K; i++) {
			// ra[mul(i, A)] = i;
			rb[mul(i, B, K)].push_back(i);
		}
		long long g = N / K;
		long long G = g * K;
		long long ans = 0;
		for (long long i = 0; i < K; i++) {
			long long n = g;
			if (i != 0 && G + i <= N) {
				n++;
			}
			long long x = mul(i, A, K);
			long long y = (K - x) % K;
			for (int k = 0; k < rb[y].size(); k++) {
				long long j = rb[y][k];
				long long m = g;
				if (j != 0 && G + j <= N) {
					m++;
				}
				if (i == j) {
					ans += n * m - n;
				} else {
					ans += n * m;
				}
				// printf("%lld %lld %lld %lld %lld %lld\n", i, x, n, j, y, m);
			}
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}