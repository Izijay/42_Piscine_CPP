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

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class 	Cat : public AAnimal
{
	public:
		Cat();
		Cat(std::string name);
		Cat(Cat const &src);
		Cat& operator=(Cat const &rhs);
		virtual ~Cat();

		virtual void		makeSound( void ) const;

		const std::string&	getIdea(int i) const;
		void			setIdea(int i, std::string &idea);

	private:
		Brain*		_brain;
};

#endif 	// CAT_HPP