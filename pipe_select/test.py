#!/usr/bin/python3

import os

out1 = os.path.join(os.path.curdir, 'in1')
out2 = os.path.join(os.path.curdir, 'in2')
os.mkfifo(out1)
os.mkfifo(out2)

o1 = open(out1, 'w')
o2 = open(out2, 'w')

for i in range(10):
    print(i, 10 - i - 1)
    print(i, file=o1)
    print(10 - i - 1, file=o2)

o1.close()
o2.close()
os.remove(out1)
os.remove(out2)
