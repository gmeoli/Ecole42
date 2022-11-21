/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:34:51 by gmeoli            #+#    #+#             */
/*   Updated: 2022/11/21 18:18:23 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int ac, char **av){

 	if (ac == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
		// for (i=0,j=0; i<x, j<y; i++, j--)... è solo un esempio
	for (size_t i = 1, j = 0; j < strlen(av[1]); i++, j++){
		putchar(toupper(av[j][i]));
	}
	return 0;
}
