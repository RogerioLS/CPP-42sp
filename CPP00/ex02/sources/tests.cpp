/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:11:19 by roglopes          #+#    #+#             */
/*   Updated: 2024/11/30 17:50:32 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"

int main()
{
	std::cout << "Creating accounts..." << std::endl;
	Account account1(1000);
	Account account2(2000);
	Account::displayAccountsInfos();

	std::cout << std::endl << "Performing deposits" << std::endl;
	account1.makeDeposit(500);
	account1.makeWithdrawal(100);
	Account::displayAccountsInfos();

	std::cout << std::endl << "Performing withdrawals" << std::endl;
	account2.makeWithdrawal(100);
	account2.makeWithdrawal(100);
	Account::displayAccountsInfos();

	std::cout << std::endl << "Displaying individual account:" << std::endl;
	account1.displayStatus();
	account2.displayStatus();

	return (0);
}