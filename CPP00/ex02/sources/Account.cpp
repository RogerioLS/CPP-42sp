/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:44:35 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/03 00:08:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * @brief Constructs an Account object with an initial deposit.
 * 
 * Initializes the account with a unique index and sets the initial balance.
 * Updates the static variables tracking the total number of accounts and total amount.
 * 
 * @param initial_deposit The initial amount deposited into the account.
 */
Account::Account(int initial_deposit)
: _accountIndex(_nbAccounts), _amount(initial_deposit),
_nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

/**
 * @brief Destructor for the Account class.
 * 
 * Logs the account closure and updates static counters.
 */
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/**
 * @brief Deposits a specified amount into the account.
 * 
 * Updates the account balance and the number of deposits made. Also updates 
 * the static counters for the total amount and total number of deposits.
 * 
 * @param deposit The amount to deposit.
 */
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

/**
 * @brief Withdraws a specified amount from the account.
 * 
 * Checks if the withdrawal amount is available. If not, logs a "refused" message.
 * Otherwise, updates the account balance and the number of withdrawals.
 * 
 * @param withdrawal The amount to withdraw.
 * @return true if the withdrawal was successful, false otherwise.
 */
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:"
			<< _amount << ";nb_withdrawals:"
			<< _nbWithdrawals 
			<< std::endl;
	return (true);
}

/**
 * @brief Returns the current balance of the account.
 * 
 * @return int The current balance.
 */
int Account::checkAmount() const
{
	return (_amount);
}

/**
 * @brief Displays the current status of the account.
 * 
 * Logs the account index, balance, number of deposits, and number of withdrawals.
 */
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals
			<< std::endl;
}

/**
 * @brief Displays aggregated information for all accounts.
 * 
 * Includes the total number of accounts, total amount across all accounts, 
 * and the total number of deposits and withdrawals.
 */
void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			<< ";total:" << _totalAmount
			<< ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals
			<< std::endl;
}
/**
 * @brief Logs the current timestamp in a specific format.
 * 
 * Used to timestamp all account operations.
 */
void Account::_displayTimestamp()
{
	std::time_t now = std::time(0);
	std::tm *ltm = std::localtime(&now);
	char buffer[20];
	strftime(buffer, sizeof(buffer), "%Y/%m/%d_%H:%M:%S", ltm);
	std::cout << "[" << buffer << "] ";
}
