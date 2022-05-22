# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    state.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 14:43:07 by gmeoli            #+#    #+#              #
#    Updated: 2022/05/22 14:43:09 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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