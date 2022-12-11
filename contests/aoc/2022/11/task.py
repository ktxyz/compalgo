DEBUG = False
NAME_DEBUG = False
if NAME_DEBUG:
    file_name = 'test.txt'
else:
    file_name = 'input.txt'


with open(file_name, 'r+', encoding='utf-8') as f:
    file_in = [x.strip() for x in f.readlines()]

def split_in(file_in):
    new_in = []
    curr_in = []
    for ele in file_in:
        if ele == '':
            new_in.append(curr_in)
            curr_in = []
        elif ele.split(' ')[0] == 'Monkey':
            continue
        else:
            curr_in.append(ele)
    new_in.append(curr_in)
    return new_in

file_in = split_in(file_in)

class Monkey:
    class Operation:
        def __init__(self, left, op, right):
            self.counter = 0
            if left == 'old':
                left, right = right, left
            self.op_sign = op
            self.value = left
            if DEBUG:
                print(self.op_sign, self.value)
        def operate(self, value):
            self.counter += 1
            right_op = self.value
            if right_op == 'old':
                right_op = value
            value = int(value)
            right_op = int(right_op)
            if self.op_sign == '+':
                return value + right_op
            elif self.op_sign == '-':
                return value - right_op
            elif self.op_sign == '/':
                return value // right_op
            else:
                return value * right_op

    def __init__(self, items_line, op_line, test_line, true_line, false_line):
        self.items = [int(x.strip()) for x in items_line.split(':')[1].split(',')]
        if DEBUG:
            print(self.items)

        op_line = op_line.split(' ')
        self.op = self.Operation(op_line[3], op_line[4], op_line[5])

        self.test = int(test_line.split(' ')[-1])
        if DEBUG:
            print('Test', self.test)

        self.true_monkey = int(true_line.split(' ')[-1])
        self.false_monkey = int(false_line.split(' ')[-1])
        if DEBUG:
            print('True', self.true_monkey, 'False', self.false_monkey)

monkeys = []
diff_tests = []

for monkey_data in file_in:
    monkey = Monkey(monkey_data[0], monkey_data[1], monkey_data[2], monkey_data[3], monkey_data[4])
    monkeys.append(monkey)
    diff_tests.append(monkey.test)

REMAINDER_VAL = 1
for test in diff_tests:
    REMAINDER_VAL *= test


CALM_DIV = 1
ROUND_NUM = 10000 #10000


if DEBUG:
    print(REMAINDER_VAL)

for r in range(ROUND_NUM):
    if DEBUG:
        print(f'Round: #{r}')
    if DEBUG:
        for midx in range(len(monkeys)):
            print(f'\tMonkey #{midx} items: ')
            print('\t\t', end='')
            for item in monkeys[midx].items:
                print(item, end=' ')
            print('')

    for idx, m in enumerate(monkeys):
        if DEBUG:
            print(f'\t\tMonkey {idx}')
            print(f'\t\tItems: {m.items}')
        while len(m.items):
            item = m.items.pop()
            if DEBUG:
                print(f'\t\t\tMonkey checks item {item}')
            item = m.op.operate(item)
            if DEBUG:
                print(f'\t\t\t\tAfter operation = {item}')
            item = item // CALM_DIV
            if DEBUG:
                print(f'\t\t\t\tMonkey gets bored = {item}')

            test_val = item % m.test
            item = item % REMAINDER_VAL

            if DEBUG:
                print(f'\t\t\t\tTest val[{m.test}] = {test_val}')

            if test_val == 0:
                if DEBUG:
                    print(f'\t\t\tITEM PASSED TO MONKEY {m.true_monkey}')
                monkeys[m.true_monkey].items.append(item)
            else:
                if DEBUG:
                    print(f'\t\t\tITEM PASSED TO MONKEY {m.false_monkey}')
                monkeys[m.false_monkey].items.append(item)

if DEBUG:
    for midx in range(len(monkeys)):
        print(f'\tMonkey #{midx} items: ')
        print('\t\t', end='')
        for item in monkeys[midx].items:
            print(item, end=' ')
        print('')

cntrs = []
for m in monkeys:
    cntrs.append(m.op.counter)

cntrs = sorted(cntrs)
print(cntrs)

print('Monkey buisness: ', cntrs[-1] * cntrs[-2])