a = input()

n, k = a.split()

n, k = int(n), int(k)

def judge_pal(pal):
    if (pal == pal[::-1]):
        return 1
    else:
        return 0

flag = 0

for i in range(0, k):
    x = judge_pal(str(n))
    if (x == 1):
        flag = 1
        print(str(n) + '\n' + str(i), end='')
        break
    else:
        n = n + int(str(n)[::-1])

if flag == 0:
    print(str(n) + '\n' + str(k), end='')