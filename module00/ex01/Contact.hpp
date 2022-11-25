/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:31:47 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/14 10:17:03 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void			displayContact(void) const;
		
		std::string		getFirstName(void) const;
		std::string		getLastName(void) const;
		std::string		getNickname(void) const;
		std::string		getPhonNumber(void) const;
		std::string		getDarkestSecret(void) const;

		void			setFirstName(std::string);
		void			setLastName(std::string);
		void			setNickname(std::string);
		void			setPhoneNumber(std::string);
		void			setDarkestSecret(std::string);

	private:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickname;
		std::string		_phoneNumber;
		std::string		_darkestSecret;
};

#endif // CONTACT_HPP