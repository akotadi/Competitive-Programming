from sys import stdin, stdout
import re

check = {}
inside = {}

class Cont:
    pad = 0
    spac = 0
    w = 0
    h = 0
    area = -1
    isContainer = False
    isVertical = False
    
    def __init__(self, name):
        self.name = name

    def setContainer(self, flag):
        self.isContainer = True
        self.isVertical = flag

    def setWindow(self, W, H):
        self.w = W
        self.h = H
        self.area = W*H

    def setPadding(self, P):
        self.pad = P

    def setSpacing(self, Sp):
        self.spac = Sp

def calcArea(name):
    if name in inside:
        for c in inside[name]:
            if check.get(c).area == -1:
                calcArea(c)

            if check.get(name).isVertical:
                check.get(name).h += check.get(c).h
                check.get(name).w = max(check.get(name).w, check.get(c).w)
            else:
                check.get(name).w += check.get(c).w
                check.get(name).h = max(check.get(name).h, check.get(c).h)

    if check.get(name).isContainer and inside.get(name) != None:
        check.get(name).w += 2 * check.get(name).pad
        check.get(name).h += 2 * check.get(name).pad
        if check.get(name).isVertical:
            check.get(name).h += check.get(name).spac * (len(inside[name])-1)
        else:
            check.get(name).w += check.get(name).spac * (len(inside[name])-1)

    check.get(name).area = check.get(name).w * check.get(name).h

n = int(stdin.readline())

for _ in range(n):
    s = stdin.readline().strip('\n')
    arr = re.split("[.(), ]",s)
    if s.find('.') != -1:
        aux = check.get(arr[0])
        if arr[1] == "add":
            if arr[0] in inside:
                inside[arr[0]].append(arr[2])
            else:
                inside[arr[0]] = [arr[2]]
        elif arr[1] == "setPadding":
            aux.setPadding(int(arr[2]))
        else:
            aux.setSpacing(int(arr[2]))
        check[arr[0]] = aux
    else:
        aux = Cont(arr[1])
        if len(arr) == 2:
            aux.setContainer(arr[0] == "VerticalContainer")
        else:
            aux.setWindow(int(arr[2]), int(arr[3]))
        check[arr[1]] = aux

for c in check.values():
    if c.area == -1:
        calcArea(c.name)

for c in sorted(check):
    stdout.write("{} {} {}\n".format(c, check.get(c).w, check.get(c).h))
