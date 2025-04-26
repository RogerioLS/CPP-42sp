/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:57:47 by codespace         #+#    #+#             */
/*   Updated: 2025/04/26 20:16:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/**
 * @brief Default constructor for the BitcoinExchange class.
 */
BitcoinExchange::BitcoinExchange() {}

/**
 * @brief Copy constructor for the BitcoinExchange class.
 * @param other The BitcoinExchange object to copy from.
 */
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : exchangeRates(other.exchangeRates) {}

/**
 * @brief Assignment operator for the BitcoinExchange class.
 * @param other The BitcoinExchange object to assign from.
 * @return A reference to the current object.
 */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        exchangeRates = other.exchangeRates;
    }
    return (*this);
}

/**
 * @brief Destructor for the BitcoinExchange class.
 */
BitcoinExchange::~BitcoinExchange() {}

/**
 * @brief Validates the date format.
 * @param date The date string to validate.
 * @throw std::invalid_argument if the date format is invalid.
 */
void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        double rate;
        
        if (std::getline(ss, date, ',') && ss >> rate)
        {
            validateDate(date);
            validateRate(rate);
            exchangeRates[date] = rate;
        }
    }
}

/**
 * @brief Retrieves the exchange rate for a given date.
 * @param date The date for which to retrieve the exchange rate.
 * @return The exchange rate for the given date.
 * @throw std::runtime_error if the date is not found.
 */
double BitcoinExchange::getExchangeRate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);
    // If the date is not found and there are no previous dates
    if (it == exchangeRates.begin() && (it == exchangeRates.end() || it->first != date)) {
        return 0; // Returns 0 if no previous date exists
    }

    // If date not found, use previous date
    if (it == exchangeRates.end() || it->first != date) {
        --it;
    }
    return (it->second);
}

/**
 * @brief Validates the date format.
 * @param date The date string to validate.
 * @return true if the date format is valid, false otherwise.
 */
bool BitcoinExchange::isValidDate(const std::string& date) const 
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (false);

    int year, month, day;
    std::stringstream(date.substr(0, 4)) >> year;
    std::stringstream(date.substr(5, 2)) >> month;
    std::stringstream(date.substr(8, 2)) >> day;

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return (false);

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);

    if (month == 2) {
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (isLeap ? 29 : 28))
            return (false);
    }

    return (true);
}

/**
 * @brief Validates the date format.
 * @param date The date string to validate.
 * @throw std::invalid data format if the date format is invalid.
 */
void BitcoinExchange::validateDate(const std::string& date) const {
    if (!isValidDate(date))
        throw std::runtime_error("Error: invalid date format => " + date);
}

/**
 * @brief Validates the exchange rate.
 * @param rate The exchange rate to validate.
 */
void BitcoinExchange::validateRate(double rate) const {
    if (rate < 0) {
        std::stringstream ss;
        ss << rate;
        throw std::runtime_error("Error: invalid exchange rate => " + ss.str());
    }
}