def gcd(x,y): 
    while(y):
        x, y = y, x % y 

    return x 

s = raw_input()
n = int(s.split()[0])
k = int(s.split()[1])
aux = gcd(n,k)
print(k*aux*(n/aux-1) + (aux-1)*(k-1))