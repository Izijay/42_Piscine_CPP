/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:41:39 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 14:41:39 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class 	Dog : public Animal
{
	public:
		Dog();
		Dog(std::string name);
		Dog(Dog const &src);
		Dog& operator=(Dog const &rhs);
		virtual ~Dog();

		virtual void		makeSound( void ) const;
		void				setIdea(int i, std::string &idea);
		const std::string&	getIdea(int i) const;
	
	private:
		Brain*	_brain;
};

#endif 	// DOG_HPP