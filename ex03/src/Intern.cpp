/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:44:50 by stopp             #+#    #+#             */
/*   Updated: 2025/01/10 16:52:30 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

Intern::Intern()
{
}
Intern::~Intern()
{
}
Intern::Intern(const Intern &copy)
{
	*this = copy;
}
Intern &Intern::operator=(const Intern &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm	*match = nullptr;
	const std::string formNames[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	AForm *constructors[] =
	{
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
			match = constructors[i];
		else
			delete constructors[i];
	}
	if (match == nullptr)
		throw std::invalid_argument("Unkown form name: " + formName);
	else
		return (match);
}
