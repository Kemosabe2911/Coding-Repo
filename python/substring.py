
def subString(s, n):
	for i in range(n):
		for len in range(i+1,n+1):
			a.append(s[i: len])

t=int(input())
for r in range(t):
    a=[]
    c=0
    n=int(input())
    s = input()
    subString(s,len(s))
    for i in range(len(a)):
        if(a[i]=='X'):
            c=c+1
        else:
            if(a[i][0]=='X'):
                if(a[i][len(a[i])-1]=='X'):
                    c=c+1
    print(c)
