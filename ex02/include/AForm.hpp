/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soren <soren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:38:05 by soren             #+#    #+#             */
/*   Updated: 2024/12/24 13:30:18 by soren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;

class	Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_GradetoSign;
		const int			_GradetoExec;

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

	public:
		Form();
		Form(const std::string &name, int GradetoSign, int GradetoExec);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();

		int					getGradetoExec(void) const;
		int					getGradetoSign(void) const;
		bool				getSigned(void) const;
		const std::string	getName(void) const;
		void				beSigned(Bureaucrat &bureaucrat);
};
std::ostream	&operator<<(std::ostream &out,const Form &form);
