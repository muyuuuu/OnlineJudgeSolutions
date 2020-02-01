num = int(input())
ls = [' '] * num;
# print(ls)
for i in range(0, num):
    ls[i] += input()
# print(ls)
x = 1
for i in ls:
    a, b, c, d = i.split(' ')
    # print(a)
    b, c, d = int(b), int(c), int(d)
    if b + c > d:
        print("Case #" + str(x) + ": true")
    else:
        print("Case #" + str(x) + ": false")
    x = x + 1


