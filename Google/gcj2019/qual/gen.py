prime_list = " ".join(open("prime.txt", 'r').read().split("\n")).split()[:26]
prime_list = list(map(int, prime_list))
print(prime_list)
text = []
import random
for i in range(26):
	text += [i] * random.randint(1, 5)
random.shuffle(text)
print("Case #1: " + "".join(map(lambda e: chr(ord('A') + e), text)))
cipher = [prime_list[text[i]] * prime_list[text[i + 1]] for i in range(len(text) - 1)]
f = open("1.in", 'w')
f.write("1\n")
f.write("%d %d\n" % (max(prime_list), len(cipher)))
f.write(" ".join(map(str, cipher)) + '\n')
f.close()