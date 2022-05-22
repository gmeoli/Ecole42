# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    capital_city.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 14:42:59 by gmeoli            #+#    #+#              #
#    Updated: 2022/05/22 14:43:01 by gmeoli           ###   ########.fr        #
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

if(len(sys.argv) != 2):
	exit()
if(capital_cities.get(states.get(sys.argv[1])) == None):
	print("Unknown state")
	exit()
print(capital_cities.get(states.get(sys.argv[1])))