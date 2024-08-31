#pragma once
#include "Person.h"

class Worker :
    public virtual Person
{
public:
    class Money {
        int amount;
        string currency;
        
        bool isCurrencyCorrect() const;
    public:
        Money() :amount(0) {};
        Money(int amount, string currency) :amount(amount), currency(currency) {};

        void setAmount();
        void setAmount(int amount) { this->amount = amount; }
        void setCurrency();
        void setCurrency(string currency) { this->currency = currency; }
        int getAmount() const { return amount; }
        string getCurrency() const { return currency; }
    };
protected:
    Money salary;
public:
    Worker(){}
    Worker(string name, string surname, Money salary): Person(name, surname), salary(salary){}

    void setSalary();
    void setSalary(Money salary) { this->salary = salary; }
    Money getSalary() const { return salary; }

    void showMainInfo() const override;
    virtual void showAchievement() const override;
};