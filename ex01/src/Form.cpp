/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soren <soren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:40:34 by soren             #+#    #+#             */
/*   Updated: 2024/12/24 13:40:57 by soren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _GradetoSign(150), _GradetoExec(150)
{
}
Form::Form(const std::string &name, int GradetoSign, int GradetoExec) : _name(name), _isSigned(false), _GradetoSign(GradetoSign), _GradetoExec(GradetoExec)
{
	if (GradetoExec < 1 || GradetoSign < 1)
		throw GradeTooHighException();
	else if (GradetoExec > 150 || GradetoSign > 150)
		throw GradeTooLowException();
}
Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _GradetoSign(copy._GradetoSign), _GradetoExec(copy._GradetoExec)
{
}
Form	&Form::operator=(const Form &copy)
{
	if (this != &copy)
		this->_isSigned = copy._isSigned;
	return (*this);
}

Form::~Form()
{
}
int	Form::getGradetoExec(void) const
{
	return (_GradetoExec);
}
int	Form::getGradetoSign(void) const
{
	return (_GradetoSign);
}
bool		Form::getSigned(void) const
{
	return (_isSigned);
}
const std::string	Form::getName(void) const
{
	return (_name);
}

void		Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_GradetoSign)
		throw GradeTooLowException();
	else
		_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "Formname: " << form.getName() << "\nGrade to Sign: " << form.getGradetoSign() << "\nGrade to Execute: " << form.getGradetoExec() << "\nStatus: ";
	if (form.getSigned() != true)
		std::cout << "Not Signed!" << std::endl;
	else
		std::cout << "Signed!" << std::endl;
	return out;
}

