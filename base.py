a,b,c = input().split()

if a == b and b == c :
    print("*")
elif a == b and b != c:
    print("C")
elif b == c and c != a:
    print("A")
else :
    print("B")