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

if len(sys.argv) != 2:
	exit()
for key, value in capital_cities.items():
	if value == sys.argv[1]:
		for key1, value1 in states.items():
			if key == value1:
				print(key1)
				exit()
print("Unknown capital city")
exit()