/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:16:46 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/13 18:37:58 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( void ) : _accountIndex(Account::_nbAccounts), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";created" << std::endl;
}

Account::Account( int initial_deposit ) : _accountIndex(Account::_nbAccounts),
								_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";created" << std::endl;
}


void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	if (deposit < 0)
		std::cout << "deposit:refused" << std::endl;
	else
	{
		Account::_totalAmount += deposit;
		std::cout << "p_amount:" << this->_amount << ";";
		this->_nbDeposits++;
		std::cout << "deposit:" << deposit << ";";
		this->_amount += deposit;
		std::cout << "amount:" << this->_amount << ";";
		Account::_totalNbDeposits++;
		std::cout << "nb_deposits:" << Account::_nbDeposits << std::endl;
	}
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal < 0 || withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		std::cout << "amount:" << this->_amount << ";";
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout << "nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
		return (true);
	}
}

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this-> _amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	//std::cout << "[19920104_091532] "; same as subject.

	std::time_t t = std::time(0);
    char mbstr[100];
    if (std::strftime(mbstr, sizeof(mbstr), "%Y%m%d", std::localtime(&t)))
        std::cout << "[" << mbstr << "_" << t << "] ";
}

Account::~Account( void )
{
	static int i = 0;
	static int j = 0;
	static int amount[7];

	amount[i] = this->_amount;
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	i++;
	if (i == 8)
	{
		i--;
		while (i >= 0)
		{
			Account::_displayTimestamp();
			std::cout << "index:" << j << ";";
			std::cout << "amount:" << amount[j] << ";closed" << std::endl;
			i--;
			j++;
		}
	}
}
