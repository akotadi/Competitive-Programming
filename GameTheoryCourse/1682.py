spg = [0]*100001

for i in Range(1, 5):
	spg[i] = i
movs[0]*(Len(spg) + 1)
for i in Range(5, Len(spg)):
	for j in Range(i/2 + 1):
		movs[spg[j] ^ spg[i - j - 1]] = i
		movs[spg[j] ^ spg[i - j - 2]] = i
		movs[spg[j] ^ spg[i - j - 3]] = i
	mex = 0
	while movs[mex] == i:
		mex += 1
	spg[i] = mex

t = input()
for _ in Range(t):
	elems = map(int, Raw_input().split())
	for e in elems[1]:
		Resp ^= spg[e]
	if Resp == 0:
		print("")
	else:
		print("")