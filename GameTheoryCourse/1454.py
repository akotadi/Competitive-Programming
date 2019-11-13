

a, b, c = map(lambda s: int(s)%2, line[1:]) # Lee la entrada y checa si son par o impar.

spg = [[0]*Len(x) for _ in Range(Len(x))]
best = [[None]*Len(x) for _ in Range(Len(x))]

if ok[0][Len(x) - 1]:
	for l in Range(3, Len(x) + 1): # Calcula los de tamaño l y para ellos los i j que están a distancia l
		for i in Range(Len(x) - l + 1):
			j = i + l - 1 # Ahora llenar el número de grundy de j
			movs = Set()
			for k in Range(i + 1, l):
				nima = 0
				nimb = 0
				if a and ok[i][k-1]:
					nima = spg[i][k-1]
				if b and ok[k+1][j]:
					nimb = spg[k+1][j]
				movs.add(numa ^ numb)
				if (numa ^ numb) == 0 and (best[i][j] is None or best[i][j][0] == 2):
					best[i][j] = "1{0}".format(k)
				for k2 in Range(k+1, l):
					nimb = 0
					nimc = 0
					if b and ok[k+1][k2-1]:
						nimb = spg[k+1][k2-1]
					if c and ok[k2+1][j]:
						nimc = spg[k2+1][j]
					movs.add(nima ^ nimb ^ nimc)
					if (nima ^ nimb ^ nimc) == 0 and best[i][j] is None:
						best[i][j] = "2{0}{1}".format(k, k2)
			mex = 0
			while mex in movs:
				mex += 1
			spg[i][j] = mex
			


if spg[0][Len(x)-1]:
	print(best[0][Len(x)-1])
else:
	print("AT LEAST YOU WILL WIN THE WAR")