/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:05:34 by mdupuis           #+#    #+#             */
/*   Updated: 2022/07/07 11:03:12 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <fstream>

template<typename T>
typename	T::iterator easyfind(T &container, int nbr)
{
	typename T::iterator it = std::find(container.begin(), container.end(), nbr);
	if (it != container.end()) {
		std::cout << *it << " found !" << std::endl;
		return it;
	}
	else {
		std::cout << "Not found" << std::endl;
		return (container.end());
	}
}