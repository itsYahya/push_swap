#!/usr/bin/env python3

import random
import sys

lst = range(0, 9999);
arg = int(sys.argv[1])
for i in random.sample(lst, arg):
	print(i, end = ' ')
	