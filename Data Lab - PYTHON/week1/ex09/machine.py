# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    machine.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 19:58:12 by gmeoli            #+#    #+#              #
#    Updated: 2022/05/22 21:45:46 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import random
from beverages import *

class CoffeeMachine:
	def __init__(self):
		self.count = 0

	class EmptyCup(HotBeverage):
		def __init__(self, name = "empty cup", price = 0.90, description = "An empty cup?! Gimme my money back!"):
			super().__init__(name, price, description)

	class BrokenMachineException(Exception):
		def __init__(self, *args: object) -> None:
			super().__init__("This coffee machine has to be repaired.")
		
	def repair(self):
		self.count = 0
		print("The machine has been repaired!")

	def serve(self, beverage):
		if self.count == 10:
			raise self.BrokenMachineException()
		self.count += 1
		if random.randint(1,2) % 2 == 0:
			return beverage()
		else:
			return self.EmptyCup()

if len(sys.argv) != 1:
	exit()
a = [HotBeverage, Coffee, Tea, Chocolate, Cappuccino] * 4
b = CoffeeMachine()
for x in a:
	try:
		z = b.serve(x)
		print(z)
	except b.BrokenMachineException as ex:
		print(ex)
		b.repair()