/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:31:20 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/13 12:22:05 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
		complainPtr[0] = &Harl::_debug;
		complainPtr[1] = &Harl::_info;
		complainPtr[2] = &Harl::_warning;
		complainPtr[3] = &Harl::_error;
}

Harl::~Harl()
{
}

void	Harl::_debug()
{
	std::cout << "DEBUG called : \"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\"" << std::endl;	
}

void	Harl::_info()
{
	std::cout << "INFO called : \"I cannot believe adding extra bacon costs more money. You didn\'t put\
enough bacon in my burger! If you did, I wouldn\'t be asking for more!\"" << std::endl;
}

void	Harl::_warning()
{
	std::cout << "WARNING called : \"I think I deserve to have some extra bacon for free. I\'ve been coming for\
years whereas you started working here since last month.\"" << std::endl;
}

void	Harl::_error()
{
	std::cout << "ERROR called : \"This is unacceptable ! I want to speak to the manager NOW !\"" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string complain_str[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int i = 0;
	for ( ; i < 4; i++)
	{
		if (level == complain_str[i])
			break;
	}
	switch (i)
	{
		case 0:
			(this->*complainPtr[0])();
		case 1:
			(this->*complainPtr[1])();
		case 2:
			(this->*complainPtr[2])();
		case 3:
			(this->*complainPtr[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}