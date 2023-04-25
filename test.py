def read_from_file(name):
    rs = []
    with open(str(name) + '.out', 'r') as f:
        for line in f.readlines():
            tmp = line.split(' ')
            tmp[-1] = tmp[-1].strip('\n')
            rs.append(tmp)
    return rs

out = read_from_file('out')
rs = read_from_file('rs')

sz = len(out)
for idx in range(sz):
    correct = True
    for ele1, ele2 in zip(out[idx], rs[idx]):
        if (ele1.lower() != ele2.lower()):
            correct = False
            break
    print("Test " + str(idx+1) + ": ", end='')
    if (correct):
        print('\033[1;32m Passed\033[0;0m')
    else:
        print('\033[1;31m Failed\033[0;0m')
        print('         \033[1;33mAnswer is: \033[0;0m\033[1;32m' + ele1 + '\033[0;0m\033[1;33m, but found: \033[0;0m\033[1;31m' + ele2 + '\033[0;0m')
