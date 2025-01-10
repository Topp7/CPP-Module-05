/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:38:05 by soren             #+#    #+#             */
/*   Updated: 2025/01/10 15:04:47 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
class Bureaucrat;

class	AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_GradetoSign;
		const int			_GradetoExec;
		std::string			_target;

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	public:
		AForm();
		AForm(const std::string &name, int GradetoSign, int GradetoExec, bool isSigned, const std::string &target);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		~AForm();

		int					getGradetoExec(void) const;
		int					getGradetoSign(void) const;
		bool				getSigned(void) const;
		const std::string	getName(void) const;
		void				beSigned(Bureaucrat &bureaucrat);
		const std::string	&getTarget() const;
		void				execute(Bureaucrat const &executor) const;
		virtual void		execute_action(void) const = 0;
};
std::ostream	&operator<<(std::ostream &out,const AForm &form);
