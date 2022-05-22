# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    beverages.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 14:42:06 by gmeoli            #+#    #+#              #
#    Updated: 2022/05/22 20:30:15 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

class HotBeverage:
	def __init__(self, name = "hot beverage", price = 0.30, description = "Just some hot water in a cup."):
		self.name = name
		self.price = price
		self.descri = description

	def description(self):
		return self.descri

	def __str__(self):
		return "name : {}\nprice : {:.2f}\ndescription : {}".format(self.name, self.price, self.description())

class Coffee(HotBeverage):
	def __init__(self, name = "coffee", price = 0.40, description = "A coffee, to stay awake."):
		super().__init__(name, price, description)

class Tea(HotBeverage):
	def __init__(self, name = "tea", price = 0.30, description = "Just some hot water in a cup."):
		super().__init__(name, price, description)

class Chocolate(HotBeverage):
	def __init__(self, name = "chocolate", price = 0.50, description = "Chocolate, sweet chocolate..."):
		super().__init__(name, price, description)	

class Cappuccino(HotBeverage):
	def __init__(self, name = "cappuccino", price = 0.45, description = "Un po' di Italia nella sua tazza!"):
		super().__init__(name, price, description)

a = HotBeverage()
b = Coffee()
c = Tea()
d = Chocolate()
e = Cappuccino()

if len(sys.argv) != 1:
	exit()
print(f"{a}\n{b}\n{c}\n{d}\n{e}")