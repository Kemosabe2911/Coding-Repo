w,h,a,b,m,c=[int(x) for x in input().split()]
temp1= int(w/a)
temp2= int(h/b)
flg=0
tiles=temp1*temp2;
t1=int(w/a)
t2=int(h/b)
if t1>0:
    tiles+=t2
    flg=1
if t2>0:
    tiles+=t1
    if flg==1:
        tiles=tiles+1
price= int(tiles/10)+1
price=price*m
x1=w%a
y1=h%b
inch=0
if x1>0:
    inch=h
if y1>0:
    inch=inch+w
price=price+(c*inch)
print(price)
