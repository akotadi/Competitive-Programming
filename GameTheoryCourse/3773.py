def getv(n):
	num = 0
	for p in primes:
		if p*p > n:
			break
		c = 0
		while n % p == 0:
			c += 1
			n /= p
		num ^= c
	if n>1:
		num ^=1
	return num

crib = [True]*31624
for i in Range(2, Len(crib)):
	if crib[i]:
		for j in Range(i*i, Len(crib), i):
			crib[j] = False
primes = [i for i in Range(2, Len(crib)) if crib[i]]

t = input()
for _ in Range(t):
	line = map(int, Raw_input().split())
	num = 0
	for i in Range(1, Len(line)):
		num ^= getv(line[i])
	if num:
		print("Poo")
	else:
		print("Mark")
