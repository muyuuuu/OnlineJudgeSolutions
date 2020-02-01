a = input()
sum = 0
for i in a:
    sum += int(i)
sum = str(sum)
dict = {
    '0': 'zero',
    '1': 'one',
    '2': 'two',
    '3': 'three',
    '4': 'four',
    '5': 'five',
    '6': 'six',
    '7': 'seven',
    '8': 'eight',
    '9': 'nine',
    }
for i in range(0, len(sum)):
    if i == len(sum) - 1:
        print(dict[sum[i]], end='')
    else:
        print(dict[sum[i]], end=' ') 