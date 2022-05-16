from curses.ascii import isdigit
import sys
if len(sys.argv) != 3:
	print("Error")
	exit()
x = (sys.argv[1]) 
y = (sys.argv[2])
if (not x.isdigit() or not y.isdigit()):
	print("Error")
	exit()
x = int(x) 
y = int(y)
print(x+y)