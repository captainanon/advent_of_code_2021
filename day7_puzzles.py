import numpy as np
import time

start = time.time()

file = open('input.txt')
line = file.readline()
positions = [int(x) for x in line.split(',')]
positions = np.array(positions)

maximum = max(positions)
minimum = min(positions)

loss_func = lambda x: x * (x + 1) / 2
losses = {}

for x in range(minimum, maximum + 1):
    # loss function for puzzle 1
    #loss = np.sum(np.absolute(positions - x))

    #loss function for puzzle 2
    loss = np.sum(loss_func(np.absolute(positions - x))).astype(np.int64)
    losses[x] = loss

min_loss = min(losses.values())
min_loss_key = min(losses, key=losses.get)

print(f"x_pos={min_loss_key}, fuel={min_loss}")

end = time.time()
print(end - start)
