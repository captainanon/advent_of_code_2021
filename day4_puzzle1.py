import numpy as np

f = open('input.txt')

nums = f.readline().split(',')

nums = [int(x) for x in nums]

lst = f.read().split('\n')

lst = list(filter(lambda x: x != '', lst))

lst2 = []

for s in lst:
    lst2.extend(s.split(' '))

lst2 = list(filter(lambda x: x != '', lst2))

lst2 = [int(x) for x in lst2]

hash = [0] * len(lst2)

for num in nums:
    for idx, val in enumerate(lst2):
        if val == num:
            hash[idx] = 1
    col1 = [sum(hash[i:i + 25:5]) for i in range(0, len(hash), 25)]
    col2 = [sum(hash[i:i + 25:5]) for i in range(1, len(hash), 25)]
    col3 = [sum(hash[i:i + 25:5]) for i in range(2, len(hash), 25)]
    col4 = [sum(hash[i:i + 25:5]) for i in range(3, len(hash), 25)]
    col5 = [sum(hash[i:i + 25:5]) for i in range(4, len(hash), 25)]
    if 5 in col1:
        winner = ('col1', col1.index(5))
        break
    if 5 in col2:
        winner = ('col2', col2.index(5))
        break
    if 5 in col3:
        winner = ('col3', col3.index(5))
        break
    if 5 in col4:
        winner = ('col4', col4.index(5))
        break
    if 5 in col5:
        winner = ('col5', col5.index(5))
        break
    rows = [sum(hash[i:i + 5]) for i in range(0, len(hash), 5)]
    if 5 in rows:
        winner = ('rows', rows.index(5) // 5)
        break

idx = winner[1]
hash = hash[idx * 25:idx * 25 + 25]
inv_hash = list(map(lambda x: 0 if x == 1 else 1, hash))
inv_hash = np.array(inv_hash)

card = lst2[idx * 25:idx * 25 + 25]
card = np.array(card)
sum = (inv_hash * card).sum() * num
print(sum)


