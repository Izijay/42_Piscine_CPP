/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:38:30 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/15 11:13:41 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Heap is accessible by all the differents fctn that are called. Need to be deleted.
// Stack is accessible only in the fctn that call it (local, like an index or smting like that).
// And is deleted when we quit the fctn.

int		main(void)
{
	try{
		Zombie	*heapOne = newZombie("heapOne");
		heapOne->announce();
		randomChump("stackOne");
		delete heapOne;
		return (0);
	}	
	catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
		return (0);
	}
}
