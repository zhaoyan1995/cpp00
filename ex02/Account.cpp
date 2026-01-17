/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:03:43 by yanzhao           #+#    #+#             */
/*   Updated: 2026/01/17 22:55:29 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    :_accountIndex(_nbAccounts),
    _amount(initial_deposit),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";" << "created" << std::endl;
    _nbAccounts++;
    _totalAmount += initial_deposit;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";" << "closed" << std::endl;
}

void	Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    struct tm *tm = std::localtime(&now);

    int year = 1900 + tm->tm_year;
    int month= 1 + tm->tm_mon;
    int day = tm->tm_mday;
    int hour = tm->tm_hour;
    int min = tm->tm_min;
    int sec = tm->tm_sec;

    std::cout << "[" << year;
    std::cout << std::setfill('0') << std::setw(2) << month;
    std::cout << std::setfill('0') << std::setw(2) << day << "_";
    std::cout << std::setfill('0') << std::setw(2) << hour;
    std::cout << std::setfill('0') << std::setw(2) << min;
    std::cout << std::setfill('0') << std::setw(2) << sec;
    std::cout << "] ";
}

int     Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int     Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int     Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int     Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void    Account::displayStatus(void)const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex  << ";";
    std::cout << "amount:" << this->_amount  << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex  << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    this->_amount += deposit;
    std::cout << "amount:" << this->_amount << ";";
    this->_nbDeposits++;
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

int     Account::checkAmount(void)const
{
    return (this->_amount);
}

bool    Account::makeWithdrawal(int withdrawl)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex  << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    if (withdrawl > checkAmount())
    {
        std::cout << "withdrawal:" << "refused" << std::endl;
        return (false);
    }
    else
        std::cout << "withdrawal:" << withdrawl << ";";
    this->_amount -= withdrawl;
    std::cout << "amount:" << this->_amount << ";";
    this->_nbWithdrawals++;
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    _totalAmount -= withdrawl;
    _totalNbWithdrawals++;
    return (true);
}
