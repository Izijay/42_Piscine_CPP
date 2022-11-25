/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:26:35 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/13 18:34:39 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string>

class Harl
{
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
		void	(Harl::*complainPtr[4])();
	private:
		void	_debug();
		void	_info();
		void	_warning();
		void	_error();
};

#endif // HARL_HPP