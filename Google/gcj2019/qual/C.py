def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)

ttt = int(input())
for tt in range(1, ttt + 1):
	n, l = map(int, input().split())
	c = list(map(int, input().split()))
	p = [0] * (l + 1)
	for i in range(l - 1):
		g = gcd(c[i], c[i + 1])
		if g != c[i]:
			p[i + 1] = g
			for j in range(i, -1, -1):
				p[j] = c[j] // p[j + 1]
			for j in range(i + 2, l + 1):
				p[j] = c[j - 1] // p[j - 1]
			break
	# print([p[i] * p[i + 1] for i in range(len(p) - 1)])
	prime = sorted(list(set(p)))
	d = {prime[i]: chr(ord('A') + i) for i in range(len(prime))}
	text = "".join([d[e] for e in p])
	print("Case #%d: %s" % (tt, text))