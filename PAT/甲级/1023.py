k = int(input())
a = k * 2

k = str(k)
a = str(a)
c = a

a = list(a)
k = list(k)

a.sort()
k.sort()

if (a == k):
    print('Yes\n' + c, end='')

else:
    print('No\n' + c, end='')
