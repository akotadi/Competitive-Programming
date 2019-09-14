from sys import stdin, stdout  
import math

def main(): 

    t = (int)(stdin.readline()) 
    # stdout.write(str(t) + "\n\n")
    for x in xrange(1,t+1):
        s = stdin.readline()
        a = int(s.split()[0])
        b = int(s.split()[1])
        d = int(s.split()[2])
        d2 = math.sqrt(math.pow(d / 2,2) + math.pow(d / 2,2))
        square = (math.pow(d, 2) / 2)
        circle = (math.pi * (math.pow(d / 2, 2)))
        circle2 = (math.pi * (math.pow(d2 / 2, 2)))

        # stdout.write(str(square) + "\n")
        # stdout.write(str(circle) + "\n")
        # stdout.write(str(circle2) + "\n")
        stdout.write(str(((circle2 / 2) - ((circle - square) / 4)) * 4) + "\n")
  
# call the main method 
if __name__ == "__main__": 
    main()     