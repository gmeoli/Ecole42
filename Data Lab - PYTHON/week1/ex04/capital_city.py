import sys

states = {
"Oregon" : "OR",
"Alabama" : "AL",
"New Jersey": "NJ",
"Colorado" : "CO"
}

capital_cities = {
"OR": "Salem",
"AL": "Montgomery",
"NJ": "Trenton",
"CO": "Denver"
}

if(len(sys.argv) != 2):
	exit()
if(capital_cities.get(states.get(sys.argv[1])) == None):
	print("Unknown state")
	exit()
print(capital_cities.get(states.get(sys.argv[1])))