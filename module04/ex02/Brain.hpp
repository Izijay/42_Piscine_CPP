/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:36:43 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 16:36:43 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class 	Brain
{
	public:
		Brain(void);
		Brain(Brain const &src);
		Brain&	operator=(const Brain& rhs);
		~Brain(void);

		void	setIdea(int i, std::string &idea);
		const std::string&	getIdea(int i) const;
	
	private:
		std::string _ideas[100];
};
