/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:57:26 by codespace         #+#    #+#             */
/*   Updated: 2025/04/10 01:24:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <stdexcept>

# define DB_FILE "../data/data.csv"

/**
 * @file BitcoinExchange.hpp
 * @class BitcoinExchange
 * @brief Header file for the BitcoinExchange class.
 * @details This file contains the declaration of the BitcoinExchange class,
 * which is responsible for handling the exchange rates of Bitcoin. It includes
 * methods for parsing data from a CSV file, validating dates, and performing
 * calculations related to Bitcoin exchange rates.
 */
class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void loadDatabase(const std::string& filename);
        double getExchangeRate(const std::string& date) const;
        void validateDate(const std::string& date) const;
        
    private:
        std::map<std::string, double> exchangeRates;

        bool isValidDate(const std::string& date) const;
        void parseCSV(const std::string& filename);
        void validateRate(double rate) const;

};

#endif