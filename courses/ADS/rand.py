import random
import sys

print int(float(sys.argv[1]))

data=range(0,int(float(sys.argv[1])))
random.shuffle(data)
for i in data:
	print i


