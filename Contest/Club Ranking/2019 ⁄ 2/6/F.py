from sys import stdin, stdout  
import math

# def SieveOfEratosthenes(n): 
      
#     # Create a boolean array "prime[0..n]" and initialize 
#     #  all entries it as true. A value in prime[i] will 
#     # finally be false if i is Not a prime, else true. 
#     prime = [True for i in range(n+1)] 
#     p = 2
#     while (p * p <= n): 
          
#         # If prime[p] is not changed, then it is a prime 
#         if (prime[p] == True): 
              
#             # Update all multiples of p 
#             for i in range(p * 2, n+1, p): 
#                 prime[i] = False
#         p += 1

def sieve_of_eratosthenes(n):
    is_prime = [True] * (n+1)
    primes = [2]

    for p in range(3, n + 1, 2):
        if is_prime[p]:
            primes.append(p)

            for multiple in range(p * p, n + 1, p + p):
                is_prime[multiple] = False

    return is_prime

def main(): 

    is_prime = sieve_of_eratosthenes(10010)

    t = (int)(stdin.readline()) 
    # stdout.write(str(t) + "\n\n")
    for x in xrange(1,t+1):
        s = stdin.readline()
        n = int(s.split()[0])
        stdout.write("Case #" + str(x) + ": ")
        if n == 1:
            stdout.write(str(1) + "\n")
        elif is_prime[n]:
            stdout.write(str(int(math.pow(2, n-1) % n)) + "\n")
        else:
            stdout.write(str(int(math.pow(n-1, 2) % n)) + "\n")
  
# call the main method 
if __name__ == "__main__": 
    main()     