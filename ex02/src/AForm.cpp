/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:40:34 by soren             #+#    #+#             */
/*   Updated: 2025/01/10 15:27:28 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _GradetoSign(150), _GradetoExec(150)
{
}
AForm::AForm(const std::string &name, int GradetoSign, int GradetoExec, bool isSigned, const std::string &target) : _name(name), _isSigned(isSigned), _GradetoSign(GradetoSign), _GradetoExec(GradetoExec), _target(target)
{
	if (GradetoExec < 1 || GradetoSign < 1)
		throw GradeTooHighException();
	else if (GradetoExec > 150 || GradetoSign > 150)
		throw GradeTooLowException();
}
AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _GradetoSign(copy._GradetoSign), _GradetoExec(copy._GradetoExec), _target(copy._target)
{
}
AForm	&AForm::operator=(const AForm &copy)
{
	if (this != &copy)
		this->_isSigned = copy._isSigned;
	return (*this);
}

AForm::~AForm()
{
}
int	AForm::getGradetoExec(void) const
{
	return (_GradetoExec);
}
int	AForm::getGradetoSign(void) const
{
	return (_GradetoSign);
}
bool		AForm::getSigned(void) const
{
	return (_isSigned);
}
const std::string	AForm::getName(void) const
{
	return (_name);
}

void		AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_GradetoSign)
		throw GradeTooLowException();
	else
		_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "NotSignedException";
}

const std::string &AForm::getTarget() const
{
	return (_target);
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw NotSignedException();
	if (executor.getGrade() > getGradetoExec())
		throw GradeTooLowException();
	this->execute_action();
}

std::ostream	&operator<<(std::ostream &out, const AForm &form)
{
	out << "Formname: " << form.getName() << "\nGrade to Sign: " << form.getGradetoSign()
	<< "\nGrade to Execute: " << form.getGradetoExec() << "\nStatus: " << (form.getSigned() ? "Signed" : "Not signed") << std::endl;
	return out;
}
