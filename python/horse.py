t=int(input())
a=[]
sd=999
b=[]
for r in range(t):
    n=int(input())
    a=input().split()
    for i in range(0,n):
        a[i]=int(a[i])
    for i in range(0,n):
        for j in range(0,n):
            if(a[i]==a[j]):
                continue
            else:
                temp= a[i]-a[j]
                if(temp<0):
                    temp = temp*-1
                if(temp<sd):
                    sd=temp
            j=j+1
        i=i+1
    b.append(sd)
    r=r+1

for r in range(t):
    print(b[r])  