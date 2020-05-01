import time
from sys import stdin, stdout
from math import ceil

def calc(n):
    ans = 0
    idx = 1
    down = 0
    power = 1
    nxt = (1 << idx+1)
    while True:
        up = n + power
        if up < nxt:
            break
        ans += power * int(up/nxt)
        power = nxt
        idx += 1
        nxt = (1 << idx)
    stdout.write(str(ans) + "\n")
    return ans

tc = int(stdin.readline())
for _ in range(tc):
    a, b = map(int, stdin.readline().split())
    stdout.write(str(calc(b) - calc(a-1)) + "\n")

