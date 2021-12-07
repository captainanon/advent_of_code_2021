import numpy as np

file = open('input.txt')
line = file.readline()
positions = [int(x) for x in line.split(',')]
positions = np.array(positions)

maximum = max(positions)
minimum = min(positions)

losses = {}

for x in range(minimum, maximum + 1):
    #loss function for puzzle 1
    #loss = np.sum(np.absolute(positions - x))

    #loss function for puzzle 2
    loss = list(np.absolute(positions - x))
    loss = [sum(range(1, 1 + x)) for x in loss]
    loss = np.array(loss)
    loss = np.sum(loss)
    losses[x] = loss

min_loss = min(losses.values())
min_loss_key = min(losses, key=losses.get)

print(f"x_pos={min_loss_key}, fuel={min_loss}")
