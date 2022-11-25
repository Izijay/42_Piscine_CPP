/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:37:22 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/23 15:30:42 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm(" << _target << ") constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm(" << _target << ") copy constructor called" << std::endl;
	*this = src;
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "ShrubberyCreationForm(" << _target << ") assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return *this;
}

std::string	const &ShrubberyCreationForm::getTargetName() const
{
	return _target;
}


void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	os;
	std::string		fileName = _target + "_shrubbery";

	try{
		if(this->getSigned() == false)
			throw AForm::FormNotSignedException();
		else if (executor.getGrade() > 137)
			throw AForm::GradeTooLowException();
		else
		{
			os.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);
			if (os.fail())
			{
				std::cout << "Error: cannot open file " << fileName << std::endl;
				return ;
			}
			os << "                                           =:  .=-                                        " << std::endl;
			os << "                                         -====-.+---                                      " << std::endl;
			os << "                                    ..:==++=+++**+-:=:   .                                " << std::endl;
			os << "                                 .-++==+++**++=+=++=. =+++=--:::                          " << std::endl;
			os << "              -:..::--:==-.       ==++++++=+**#*+-+-:.=+*+=-++++=++=.                     " << std::endl;
			os << "            -::-=-==++=-::..   .-::==+*+=*+++***+=+++=++***+****++*+=:                    " << std::endl;
			os << "          :-==+===+=+++=-=--:---=++++=**###*=***###%*##*##******+=+++=.                   " << std::endl;
			os << "           -==+-=+++*++++-=+*++++****+#%%#***#%#*###*#***####****++*+-:---                " << std::endl;
			os << "       ..:=++=:====+==++*+*##+*##*#++++##=++%%##**+*+*##%%######**++===++=:-.             " << std::endl;
			os << "       .:.==-++=**++++==+==**##+#***##++=+=++*+=*##*+**++**###%#*++++=======:.            " << std::endl;
			os << "           :::---=---===++*==+**%%##%%#+++==*+++===+==#****%%%##****+=+=++++-.            " << std::endl;
			os << "          .:-=:==+*====+=+*****#%%%***##++++++*++==--==++=*#%####*+**++=====              " << std::endl;
			os << "           .-=+*+:===+=+*###****#*##+*%#+==+++**++++=+=+++=+#+=+++==**+===+=--=-:         " << std::endl;
			os << "         .-=*+=-=+++*#*****#%#**#%##%#####=*++**++*++++==+==+***+===+**++==-++====:.      " << std::endl;
			os << "        :==++++++****#**===+=*++###*+++****++****+***+++++===*+=+**++++===++++=++=+:      " << std::endl;
			os << "      .:=+++*****+*#*++#%*+++#*+##%++=+=+++=+++=+*##*****++=-+***####**++=-+##*+===-.:==- " << std::endl;
			os << "        +*###***+*%%%%###+=*+**##%*+**#*#%###**+**##*#*****++=+#%%#######*=***=++++*+--:  " << std::endl;
			os << "        =+**#*++*%%%%**##*+++#**#***##**+*##%%#*+***#*#*++++#++%%%%%%%%%##*#*+==+++===-==:" << std::endl;
			os << "        .:=:-+#*#%%%%####++=+++***###+********#**##**##*+#*#%*##%%%%@%%%%####*+*+=+===+=: " << std::endl;
			os << "     .=-+=:-:**##%###*%%*+*#++**####*=****+**+====+**=+*=*++*+==%@#%%%%%%%#*##*=+*++++==: " << std::endl;
			os << " .==++*+**+*#%#%%%%#%@@@###@####*#%%#####%###*++*+*+##**+=#++*#*#%#%%%%###****#*==++++=-- " << std::endl;
			os << " :=*==-=++*%#%%@%#%%%%%########*#%##*#%###%%%****+*##*==##+=-++=+*%%%%#%########**++=+.   " << std::endl;
			os << ".-:-==+++*###%######*+****#%##%*#######*%%%######+=#*+=*%%+****##*#*+#%#####*+*#++*+=.    " << std::endl;
			os << "    ::-=*+*+*#*##*+*****%%####%%%#***##%##%#%%#***++#%#%%##++***###**=%%*####***+===++:.  " << std::endl;
			os << "      :=**+*###****#*########%%@#%#+#####%%%%#%#+#%@%@@*%%%######*+=*+-+****###*+-::=++-: " << std::endl;
			os << "      :-=*#####*++##*##%%%####%##%%#######%@#*##*#%@%@%###+%#%%%#*++=:. :-.+#*##+*+-:.:.  " << std::endl;
			os << "       .-=+**##%***#%%%#%#*=#%%++####%%%%%#%###*##*%%@@%#%%%%%%##***+   -#=++***#=--      " << std::endl;
			os << "         .==**#**###%#%###*+#=#*=#%##%%%####%#%##**%%@%%%%%%%%%###*+**=:.=.+*+++-=        " << std::endl;
			os << "            .+####*#%######=***##%#%%%%%####%%###++%%%%@@%%%%%%%%%###*-=+=-:-.-.          " << std::endl;
			os << "             :--+. =#***#*#*###+++**#%#%####%#####%@%%#%%%%%%@@@@%%#*+*=*#++-:            " << std::endl;
			os << "                  .*+++########**+##%##%###%#**%%@#+*%#%@%%##%@%%%#**+-:=-:=--:           " << std::endl;
			os << "                  --=+:+##*#%%**++=###%%%#**#%%#%#-=+#%%%%%=##%%#*-  .+-                  " << std::endl;
			os << "                     .=+*+*#*+-++=-+**%%%#--#%##%+###%%##%#-*%*+#*-                       " << std::endl;
			os << "                       .=-. :-++:--.:.++:-+#*##*#+**#:-###%+*#**#*+:                      " << std::endl;
			os << "                          .-:-::            ***##=+=     .+: --.-==:                      " << std::endl;
			os << "                         .-  :              *+***=             ..                         " << std::endl;
			os << "                                            *++++=                                        " << std::endl;
			os << "                                           .*+#+=+                                        " << std::endl;
			os << "                                           :*+@*+=                                        " << std::endl;
			os << "                                           =*+#**=                                        " << std::endl;
			os << "                                          =+**#*+++                                       " << std::endl;
			os << "                                       .:-=*==+*++=-." << std::endl;
			os.close();
			std::cout << "File " << fileName << " created by " << executor.getName() << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << " by " << executor.getName() << std::endl;
		return ;
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm(" << _target << ") destructor called" << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream &os, ShrubberyCreationForm const &rhs) {

	os << "Form name: " << rhs.getName() << " , 145 or more to sign, 137 or more to execute. --- Target is: " << rhs.getTargetName() << std::endl;
	return (os);
}