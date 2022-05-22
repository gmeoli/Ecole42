# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    print_sum.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 14:42:21 by gmeoli            #+#    #+#              #
#    Updated: 2022/05/22 14:42:24 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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