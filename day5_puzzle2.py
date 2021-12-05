import numpy as np

f = open('input.txt')
file = f.readlines()
lst = []

for line in file:
    coords = line.split(' ')[::2]
    coords = [x.replace('\n', '') for x in coords]
    coords = [(int(x.split(',')[0]), int(x.split(',')[1]))for x in coords]

    if coords[0][1] == coords[1][1] and coords[0] is not coords[1] and coords[0][0] < coords[1][0]:
        line = [(z, coords[0][1]) for z in range(coords[0][0], coords[1][0] + 1)]
        lst.extend(line)
    elif coords[0][1] == coords[1][1] and coords[0] is not coords[1] and coords[0][0] > coords[1][0]:
        line = [(z, coords[0][1]) for z in range(coords[0][0], coords[1][0] - 1, -1)]
        lst.extend(line)
    elif coords[0][0] == coords[1][0] and coords[0] is not coords[1] and coords[0][1] < coords[1][1]:
        line = [(coords[0][0], z) for z in range(coords[0][1], coords[1][1] + 1)]
        lst.extend(line)
    elif coords[0][0] == coords[1][0] and coords[0] is not coords[1] and coords[0][1] > coords[1][1]:
        line = [(coords[0][0], z) for z in range(coords[0][1], coords[1][1] - 1, -1)]
        lst.extend(line)
    elif coords[0] is not coords[1] and coords[0][0] < coords[1][0] and coords[0][1] < coords[1][1]:
        line = list(zip(range(coords[0][0], coords[1][0] + 1), range(coords[0][1], coords[1][1] + 1)))
        lst.extend(line)
    elif coords[0] is not coords[1] and coords[0][0] > coords[1][0] and coords[0][1] < coords[1][1]:
        line = list(zip(range(coords[0][0], coords[1][0] - 1, -1), range(coords[0][1], coords[1][1] + 1)))
        lst.extend(line)
    elif coords[0] is not coords[1] and coords[0][0] < coords[1][0] and coords[0][1] > coords[1][1]:
        line = list(zip(range(coords[0][0], coords[1][0] + 1), range(coords[0][1], coords[1][1] - 1, -1)))
        lst.extend(line)
    elif coords[0] is not coords[1] and coords[0][0] > coords[1][0] and coords[0][1] > coords[1][1]:
        line = list(zip(range(coords[0][0], coords[1][0] - 1, -1), range(coords[0][1], coords[1][1] - 1, -1)))
        lst.extend(line)
    elif coords[0] is coords[1]:
        line = coords[0]
        lst.extend(line)
    else:
        pass

max_y = max([x[0] for x in lst])
max_x = max([x[1] for x in lst])

matrix = np.zeros((max_x + 1, max_y + 1))

for pair in lst:
    matrix[pair[1], pair[0]] += 1

print(len(matrix[matrix > 1]))
