from random import seed
from random import randint

seed(1)

t = int(100)

print(t)
for _ in range(t):
	n = randint(2,int(50))
	maxv = int(n**2)
	print(str(n) + " " + str(randint(n,maxv)))