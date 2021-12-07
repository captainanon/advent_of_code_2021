f = open('input.txt')
file = f.readline()
pop = [int(x) for x in file.split(',')]

adult_dict = dict(zip(list(range(0, 7)), [0] * 7))
adolescent_dict = dict(zip(list(range(0, 9)), [0] * 9))

for fish in pop:
    adult_dict[fish] += 1

days = 256

for day in range(0, days):
    new_adolescents = adult_dict[0]
    adult_dict = {(t - 1 if t > 0 else t + 6): (c if t > 0 else c) for t, c in adult_dict.items()}

    new_adults = adolescent_dict[0]
    adolescent_dict = {(t - 1 if t > 0 else t + 8): (c if t > 0 else c) for t, c in adolescent_dict.items()}

    adult_dict[6] += new_adults
    adolescent_dict[8] += new_adolescents

adult_count = sum(adult_dict.values())
adolescent_count = sum(adolescent_dict.values())
total_pop = adult_count + adolescent_count

print(total_pop)

