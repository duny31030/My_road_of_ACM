i = int(input())

for x in range(i):
    a,b,c  = input().split()
    
    if a+b > c :
        print("Case #%d: true" % (x+1))
    else:
        print("Case #%d: false" % (x+1))
