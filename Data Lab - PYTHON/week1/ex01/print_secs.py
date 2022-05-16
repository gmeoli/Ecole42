from curses.ascii import isdigit
import sys
if len(sys.argv) != 4:
	print("Error")
	exit()
x = (sys.argv[1])
y = (sys.argv[2])
z = (sys.argv[3])
if (not x.isdigit() or not y.isdigit() or not z.isdigit()):
	print("Error")
	exit()
x = int(x)
y = int(y)
z = int(z)
print((x*3600)+(y*60)+z)