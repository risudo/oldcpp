#include "Bureaucrat.hpp"

#include <iostream>

const int Bureaucrat::maxGrade = 1;
const int Bureaucrat::minGrade = 150;

Bureaucrat::GradeTooHighException::GradeTooHighException(char const *msg)
    : std::out_of_range(msg) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(char const *msg)
    : std::out_of_range(msg) {}

Bureaucrat::Bureaucrat() : _grade(1) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    if (grade > minGrade) {
        throw GradeTooLowException("<constructor> Grade too low");
    }
    if (grade < maxGrade) {
        throw GradeTooHighException("<constructor> Grade too high");
    }
    _grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &other) { *this = other; }

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

const std::string &Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::upGrade() {
    if (_grade == maxGrade) {
        throw GradeTooHighException("<upGrade> Grade too high");
    }
    _grade++;
}

void Bureaucrat::downGrade() {
    if (_grade == minGrade) {
        throw GradeTooLowException("<downGrade> Grade too low");
    }
    _grade--;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
    out << "<" << b.getName() << ">"
        << " grade: " << b.getGrade();
    return out;
}
