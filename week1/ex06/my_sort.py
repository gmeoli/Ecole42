# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    my_sort.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 14:43:17 by gmeoli            #+#    #+#              #
#    Updated: 2022/05/22 17:02:11 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

d = {'Hendrix' : '1942',
	'Allman' : '1946',
	'King' : '1925',
	'Clapton' : '1945',
	'Johnson' : '1911',
	'Berry' : '1926',
	'Vaughan' : '1954',
	'Cooder' : '1947',
	'Page' : '1944',
	'Richards' : '1943',
	'Hammett' : '1962',
	'Cobain' : '1967',
	'Garcia' : '1942',
	'Beck' : '1944',
	'Santana' : '1947',
	'Ramone' : '1948',
	'White' : '1975',
	'Frusciante': '1970',
	'Thompson' : '1949',
	'Burton' : '1939',}

a = []

for x in d.items():
	a.append((x[1],x[0]))
a.sort()
if len(sys.argv) != 1:
	exit()
for i in a:
	print(i[1])