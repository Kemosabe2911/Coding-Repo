t=int(input())
for r in range(t):
    n= int(input())
    a=input()
    s=[]
    for i in range(n):
        s.append(a[i])
    i=0
    while(i<n):
        if(i==0):
            if(s[i]=='B'):
                if(s[i+1]=='C'):
                    s[i+1]='B'
                    i=i+2
                    continue
                else:
                    i=i+1
                    continue
            else:
                i=i+1
        else:
            if (i==n-1):
                if(s[i]=='B'):
                    if(s[i-1]=='C'):
                        s[i-1]='B'
                        break
                    else:
                        break
                else:
                    break
            else:
                if(s[i]=='B'):
                    if(s[i-1]=='C'):
                        s[i-1]='B'
                    if(s[i+1]=='C'):
                        s[i+1]='B'
                        i=i+2
                        continue
                    else:
                        i=i+1
                else:
                    i=i+1
    print(s.count('B'))