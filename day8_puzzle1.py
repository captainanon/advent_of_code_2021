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

    for digit in output:
        if len(digit) in [2, 3, 4, 7]:
            count += 1

print(count)
