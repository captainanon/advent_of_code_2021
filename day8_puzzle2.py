import numpy as np

file = open('input.txt')
lines = file.readlines()

count = 0

for line in lines:
    line = line.split('|')

    input = line[0].split(' ')
    input.pop()

    output = line[1].split(' ')
    output.pop(0)
    output = [x.replace('\n', '') for x in output]

    dict = {}

    pop_list = []
    for idx, val in enumerate(input):
        val = ''.join(sorted(val))
        if len(val) == 2:
            dict[1] = val
            pop_list.append(idx)
        elif len(val) == 4:
            dict[4] = val
            pop_list.append(idx)
        elif len(val) == 3:
            dict[7] = val
            pop_list.append(idx)
        elif len(val) == 7:
            dict[8] = val
            pop_list.append(idx)

    for x in reversed(pop_list):
        input.pop(x)

    for idx, val in enumerate(input):
        val = ''.join(sorted(val))
        if len(val) == 5 and dict[1][0] in val and dict[1][1] in val:
            dict[3] = val
            input.pop(idx)
            break

    for idx, val in enumerate(input):
        val = ''.join(sorted(val))
        if len(val) == 6 and dict[3][0] in val and dict[3][1] in val and dict[3][2] in val and dict[3][3] in val and dict[3][4] in val:
            dict[9] = val
            input.pop(idx)
            break

    for idx, val in enumerate(input):
        val = ''.join(sorted(val))
        if len(val) == 6 and dict[1][0] in val and dict[1][1] in val:
            dict[0] = val
            input.pop(idx)
            break

    for idx, val in enumerate(input):
        val = ''.join(sorted(val))
        if len(val) == 6:
            dict[6] = val
            input.pop(idx)
            break

    for idx, val in enumerate(input):
        val = ''.join(sorted(val))
        if val[0] in dict[6] and val[1] in dict[6] and val[2] in dict[6] and val[3] in dict[6] and val[4] in dict[6]:
            dict[5] = val
            input.pop(idx)

    val = ''.join(sorted(input[0]))
    dict[2] = val

    result = []

    for val in output:
        val = ''.join(sorted(val))
        for k, v in dict.items():
            if val == v:
                result.append(k)
                break

    result = [str(x) for x in result]
    result = ''.join(result)
    result = int(result)
    count += result

print(count)
