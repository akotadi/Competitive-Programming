from sys import stdin, stdout 
from math import exp, log, sqrt

n = int(stdin.readline()) 

arr = []
for i in range(n):
	arr.append(log(float(stdin.readline())))

avg = sum(arr) / n

dev = sqrt(sum((x - avg) ** 2 for x in arr) / (n-1))

stdout.write("%.2f\n" % exp(avg - (2*dev)))
stdout.write("%.2f\n" % exp(avg - dev))
stdout.write("%.2f\n" % exp(avg))
stdout.write("%.2f\n" % exp(avg + dev))
stdout.write("%.2f\n" % exp(avg + (2*dev)))
 