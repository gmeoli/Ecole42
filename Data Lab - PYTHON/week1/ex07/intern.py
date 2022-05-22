# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    intern.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 14:43:27 by gmeoli            #+#    #+#              #
#    Updated: 2022/05/22 20:29:39 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
from logging import raiseExceptions

class Intern:
	def __init__(self, name = "My name? I'm nobody, an intern, I have no name."):
		self.name = name

	def __str__(self):
		return self.name

	class Coffee:
		def __str__(self):
			return ("This is the worst coffee you evertasted.")

	def work(self):
		raise Exception("I'm just an intern, I can't do that...")

	def make_coffee(self):
		return self.Coffee()

if len(sys.argv) != 1:
	exit()
a = Intern()
b = Intern("Mark")
print(a)
print(b)
coffee = b.make_coffee()
print(coffee)
try:
	a.work()
except Exception as c:
	print(c)