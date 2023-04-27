import sys

def read_from_file(name):
    rs = []
    with open(str(name) + '.out', 'r') as f:
        for line in f.readlines():
            tmp = line.split(' ')
            tmp[-1] = tmp[-1].strip('\n')
            rs.append(tmp)
    return rs

def get_no_tc():
    with open('in.in', 'r') as f:
        tc = f.readline()
    return int(tc)

if __name__ == '__main__':
    tc = get_no_tc()
    out = read_from_file('out')
    rs = read_from_file('rs')

    if (len(sys.argv) > 1 and sys.argv[1] == 'D'):
        print('\033[1;31mDebug is on\033[0;0m')
        for elements in rs:
            for element in elements:
                print(element, end=' ')  
            print()
    else:
        for idx in range(tc):
            correct = True
            no_line = len(out)//tc
            for line in range(no_line):
                for ele1, ele2 in zip(out[idx+line], rs[idx+line]):
                    if (ele1.lower() != ele2.lower()):
                        correct = False
                        break
                print("Test " + str(idx+1) + ": ", end='')
                if (correct):
                    print('\033[1;32m Passed\033[0;0m')
                else:
                    print('\033[1;31m Failed\033[0;0m')
                    print('         \033[1;33mAnswer is: \033[0;0m\033[1;32m' + ele1 + '\033[0;0m\033[1;33m, but found: \033[0;0m\033[1;31m' + ele2 + '\033[0;0m')
