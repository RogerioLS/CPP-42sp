/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:58:56 by codespace         #+#    #+#             */
/*   Updated: 2025/04/10 00:16:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return (1);
    }

    BitcoinExchange btc;
    try {
        btc.loadDatabase(DB_FILE); // Substitua "data.csv" pelo caminho correto do arquivo de base de dados.
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }

    std::string line;
    if (std::getline(inputFile, line)) {
        if (line.find("date | value") != std::string::npos) {
            // Ignora o cabeçalho
            std::cout << "Header ignored: " << line << std::endl;
        } else {
            // Se a primeira linha não for o cabeçalho, processe-a
            inputFile.seekg(0); // Volta para o início do arquivo
        }
    }

    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            continue; // Ignora linhas em branco
        }

        std::istringstream ss(line);
        std::string date, value;

        if (std::getline(ss, date, '|') && std::getline(ss, value)) {
            date = date.substr(0, date.find_last_not_of(" \t") + 1);
            value = value.substr(value.find_first_not_of(" \t"));

            try {
                btc.validateDate(date);

                std::stringstream ssValue(value);
                double amount;
                ssValue >> amount;
                if (ssValue.fail()) {
                    throw std::runtime_error("Error: invalid value => " + value);
                }

                if (amount < 0) {
                    throw std::runtime_error("Error: not a positive number.");
                }
                if (amount > 1000) {
                    throw std::runtime_error("Error: too large a number");
                }

                double rate = btc.getExchangeRate(date);
                std::cout << date << " => " << value << " = " << rate * amount << std::endl;
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }

    return (0);
}