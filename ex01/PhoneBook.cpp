/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:26:18 by yanzhao           #+#    #+#             */
/*   Updated: 2026/01/17 22:15:21 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void):_count(0)
{
    //std::cout << "A PhoneBook instance has been created." << std::endl;
    return ;
}

PhoneBook::~PhoneBook(void)
{
    //std::cout << "A PhoneBook instance has been destroyed." << std::endl;
    return ;
}

bool    PhoneBook::addContact(void)
{
    std::string input[5];
    std::string prompt[5] = {
        "first name", 
        "last name", 
        "nick name", 
        "phone number", 
        "darkest secret"};
 
    for (int i = 0; i < 5; i++)
    {
        while (1)
        {
            std::cout << CYAN << "Enter your " << prompt[i] << ": " << RESET << std::endl;
            if (!std::getline(std::cin, input[i]))
                return (false);
            if (this->_isValideInput(input[i], prompt[i]))
                break ;
        }
    }
    this->_contacts[this->_count % 8].set_info(input[0], input[1], input[2], input[3], input[4]);
    this->_count++;
    if (this->_count > 8)
        this->_count = 8;
    std::cout << GREEN << "Contact has been added successfully." << RESET << std::endl;
    return (true);
}

static bool isAllWhiteSpace(const std::string &str)
{
    size_t i;

    if (str.empty())
        return (true);
    i = 0;
    while (i < str.length())
    {
        if (!std::isspace(static_cast<unsigned char>(str[i])))
            return (false);
        i++;
    }
    return (true);
}

static bool isAllDigit(const std::string &str)
{
    size_t i;

    if (str.empty())
        return (false);
    i = 0;
    while (i < str.length())
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return (false);
        i++;
    }
    return (true);
}

bool    PhoneBook::_isValideInput(std::string &input, std::string &prompt)const
{
    if (prompt == "phone number")
    {
        if (isAllDigit(input) == false)
        {
            std::cout << RED << "Error: your " << prompt <<
                " should only be composed by digit character from '0' to '9'." << RESET << std::endl;
            return (false);
        }
        else
            return (true);
    }
    if (isAllWhiteSpace(input) == true)
    {
        std::cout << RED << "Error: your " << prompt <<
            " can't be empty or only composed by space!" << RESET << std::endl; 
        return (false);
    }
    return (true);
}

void    PhoneBook::_printTableHeader(void)const
{
    std::cout << BLUE << "|";
    std::cout << std::setw(10) << "index";
    std::cout << "|";
    std::cout << std::setw(10) << "first name";
    std::cout << "|";
    std::cout << std::setw(10) << "last name";
    std::cout << "|";
    std::cout << std::setw(10) << "nickname";
    std::cout << "|" << RESET << std::endl;
    return ;
}

bool    PhoneBook::searchContact(void)const
{
    int index;
    std::string cmd;

    this->_printTableHeader();
    for(index = 0; index < this->_count; index++)
        this->_contacts[index].display_summary(index);
    std::cout << CYAN << "Please enter an index number to show contact details." << RESET << std::endl;
    if (!std::getline(std::cin, cmd))
        return (false);
    if (cmd.length() != 1 || !std::isdigit(cmd[0]))
        std::cout << RED << "Invalid index" << RESET << std::endl;
    else if ((cmd[0] >= '0' && cmd[0] < this->_count + '0'))
    {
        index = cmd[0] - '0';
        this->_contacts[index].display_details(); 
    }
    else
        std::cout << YELLOW << "The index number " << cmd[0] << " is out of range or empty." << RESET << std::endl;
    return (true);
}
