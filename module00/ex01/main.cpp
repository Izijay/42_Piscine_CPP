/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:49:12 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/10 12:29:09 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int		main(int ac, char **av)
{
	(void)av;
	
	if (ac != 1){
		std::cout << "No argument needed." << std::endl;
		return (0);
	}

	PhoneBook	phoneBook;
	return (0);
}