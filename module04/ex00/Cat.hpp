/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:41:31 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 14:41:31 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class 	Cat : public Animal
{
	public:
		Cat();
		Cat(std::string name);
		Cat(Cat const &src);
		Cat& operator=(Cat const &rhs);
		virtual ~Cat();

		void		makeSound( void ) const;
};

#endif 	// CAT_HPP