/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:15:02 by roglopes          #+#    #+#             */
/*   Updated: 2024/11/30 16:18:30 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>
# include <string>
# include <ctime>

class Account {

	public:
		typedef	Account t;

		static int	getNbAccounts( void );
		static int	getTotalAmount( void );
		static int	getNbDeposits( void );
		static int	getNbWithdrawals( void );
		static void	displayAccountsInfos( void );

		Account( int initial_deposit);
		~Account( void );

		void	makeDeposit( int deposit );
		bool	makeWithdrawal( int withdrawal);
		int		checkAmount( void ) const;
		void	displayStatus( void ) const;

	private:
		static void	_displayTimestamp( void );
		static int	_nbAccounts;
		static int	_totalAmount;
		static int	_totalNbDeposits;
		static int	_totalNbWithdrawals;

		int			_accountIndex;
		int			_amount;
		int			_nbDeposits;
		int			_nbWithdrawals;

		Account( void );
};
