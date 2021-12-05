import numpy as np

f = open('input.txt')
codes = [[int(x) for x in y] for y in f.read().split('\n')]
codes = np.array(codes)
codes2 = codes

i = 0

while codes.shape[0] > 1:
    most_common = 1 if np.count_nonzero(codes == 1, axis=0)[i] >= np.count_nonzero(codes == 0, axis=0)[i] else 0
    codes = codes[codes[:, i] == most_common]
    i += 1

code = ''.join(str(x) for x in list(codes[0]))
oxy = int(code, 2)

i = 0

while codes2.shape[0] > 1:
    least_common = 0 if np.count_nonzero(codes2 == 1, axis=0)[i] >= np.count_nonzero(codes2 == 0, axis=0)[i] else 1
    codes2 = codes2[codes2[:, i] == least_common]
    i += 1

code2 = ''.join(str(x) for x in list(codes2[0]))
co2 = int(code2, 2)

print(oxy * co2)
