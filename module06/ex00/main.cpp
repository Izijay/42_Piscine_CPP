/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:55:48 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/30 11:56:10 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

bool	ft_check_arg(std::string s) {

	if (s.length() == 0)
		return (false);
	if (s.length() == 1)
		return (true);
	unsigned int i = -1;
	int			point = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[++i]) {
		if (s[i] < '0' || s[i] > '9') {
			if (s == "inf" || s == "inff" || s == "+inf" || s == "+inff"
				|| s == "-inf" || s == "-inff" || s == "nan" || s == "nanf")
				return (true);
			else if (s[i] == '.' && i != 0 && point == 0 && i != s.length() - 1 && s[i + 1] != 'f')
				point = 1;
			else if (s[i] == 'f' && i == s.length() - 1)
				;
			else
				return (false);
		}
		i++;
	}
	return (true);
}

int	main(int ac, char **av) {

	if (ac != 2) {
		std::cerr << "Error, invalid argument" << std::endl;
		return (1);
	}
	if (!ft_check_arg(av[1])) {
		std::cerr << "Error, invalid value" << std::endl;
		return (1);
	}
	Convert	instance(av[1]);
	std::cout << instance;
	return (0);
}