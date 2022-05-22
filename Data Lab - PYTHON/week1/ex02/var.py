# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    var.py                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 14:42:38 by gmeoli            #+#    #+#              #
#    Updated: 2022/05/22 17:01:25 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

a = 42
b = "42"
c = "quarante-deux"
d = 42.0
f = True
g = [42]
h = {42: 42}
i = (42, )
l = set()

if len(sys.argv) != 1:
	exit()
print(a, "has a type", type(a))
print(b, "has a type", type(b))
print(c, "has a type", type(c))
print(d, "has a type", type(d))
print(f, "has a type", type(f))
print(g, "has a type", type(g))
print(h, "has a type", type(h))
print(i, "has a type", type(i))
print(l, "has a type", type(l))