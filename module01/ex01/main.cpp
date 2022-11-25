/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:38:30 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/15 11:15:40 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main(void)
{
	try{
		int N = 10;
		Zombie	*horde = zombieHorde(N, "Jean Louis");

		for (int i = 0; i < N; i++)
			horde[i].announce();
		std::cout << std::endl;
		delete [] horde;
		return (0);
	}
	catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
		return (0);
	}

}
