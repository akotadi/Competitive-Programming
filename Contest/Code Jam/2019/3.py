# import inbuilt standard input output  
from sys import stdin, stdout  
import primefac
  
def prime_factors(n):
    factors = []
    if n > 1:
        i = 2
        while n % i != 0:
            i += 1
        factors.append(i)
        factors.extend(prime_factors(n / i))
    return factors

def largest_prime_factor(n):
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
    return n

# suppose a function called main() and 
# all the operations are performed 
def main(): 
  
    # input via readline method 
    t = (int)(stdin.readline()) 
    stdout.write(str(t) + "\n\n")
    for x in xrange(1,t+1):
        s = stdin.readline()
        n = s.split()[0]
        l = s.split()[1]
        arr = [int(x) for x in stdin.readline().split()] 
        aux = 10**100
        index = 0
        count = 0
        for x in arr:
            if x < aux:
                index = count
                aux = x
            count += 1
        stdout.write(str(index) + "\n")
        stdout.write(str(arr[index]) + "\n")
        stdout.write(str(aux) + "\n")
        stdout.write(str(largest_prime_factor(aux)) + "\n")
        factors = list( primefac.primefac(aux) )
        print '\n'.join(map(str, factors))

        stdout.write("\n\n") 
  
# call the main method 
if __name__ == "__main__": 
    main()     