/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:27:16 by soren             #+#    #+#             */
/*   Updated: 2025/01/10 15:25:22 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		std::cout << "Bureaucrat created!" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
}
Bureaucrat::~Bureaucrat()
{
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
		_grade = copy.getGrade();
	return (*this);
}
const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}
void	Bureaucrat::incrementGrade(void)
{
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}
void	Bureaucrat::decrementGrade(void)
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\033[0;31mGradeTooHighException\033[0m");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "\033[0;31mGradeTooLowException\033[0m";
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade();
	return (out);
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout <<  *this << " signed " << form << std::endl;
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cout << *this << " couldnt sign " << form << std::endl;
	}

}
void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << "Grade of " << this->_name << " too low to execute." << std::endl;
	}
	catch(AForm::NotSignedException &e)
	{
		std::cout << "Form not signed." << std::endl;
	}
}
