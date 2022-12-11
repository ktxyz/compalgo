from collections import defaultdict


with open('input.txt', 'r', encoding='utf-8') as f:
    in_file = [x.strip() for x in f.readlines()]

dir_size = defaultdict(int)
path = ['@']

for line_str in in_file:
    line = line_str.split(' ')
    print(line)

    if line[0] == '$' and line[1] == 'cd':
        if line[2] == '..':
            if len(path) > 1:
                path.pop()
        elif line[2] == '/':
            path = ['@']
        else:
            path.append(line[2])
    elif line[0] != '$':
        if line[0] == 'dir':
            continue
        size = int(line[0])
        p = []
        for subp in path:
            p.append(subp)
            print('/'.join(p))
            dir_size['/'.join(p)] += size

a = 0
b = 70000000
c = 70000000
taken = dir_size['@']
for s in dir_size.values():
    if s <= 100000:
        a += s
    if (taken - s) + 30000000 <= b:
        c = min(c, s)

print(a)
print(taken, c)