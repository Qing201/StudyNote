import sys

for line in sys.stdin:
    a = line.split()
    num = 0
    length = len(a)
    for i in range(len(a)):
        num += 10**(length - i) * a[i]
        
    print(num)
