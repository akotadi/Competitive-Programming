from sys import stdin, stdout 

n = int(stdin.readline())
arr = [int(x) for x in stdin.readline().split()]

ans = 0
for i in range(32)[::-1]:
    ans <<= 1
    aux = {x >> i for x in arr}
    ans += any(ans^1 ^ p in aux for p in aux)

stdout.write(str(ans))