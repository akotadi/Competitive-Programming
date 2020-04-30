from sys import stdin, stdout 

n = int(stdin.readline())
arr = [int(x) for x in stdin.readline().split()]
s = sum(arr)
ans = 0
  
for x in arr: 
    s -= x
    ans += s * x

stdout.write(str(ans)) 