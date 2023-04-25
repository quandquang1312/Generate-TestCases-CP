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
        if (ele1 != ele2):
            correct = False
            break
    print("Test " + str(idx+1) + ": ", end='')
    if (correct):
        print('Passed')
    else:
        print('Failed')
