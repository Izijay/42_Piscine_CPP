/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 00:37:12 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/13 12:53:40 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define MAX_CONTACT 8
# include <string>
# include <cctype>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void			add(void);
		void			search(void);

	private:
		Contact	_contacts[8];
		int		_nbr;
		void	_setContact(void);
		void	_searchByIndex(void);
};

#endif // PHONEBOOK_HPP