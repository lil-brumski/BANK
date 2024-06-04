#include <iostream>
#include <string>
#include <memory>

#include "job.hpp"
#include "../bank.hpp"

std::ofstream File("salary.db", std::ios::app);

void PAY(double salary){       
        int pay = 5;
        
        std::cout << "\nReceiving salary, hold on...\n\n";
        
        std::chrono::milliseconds duration(1000 * pay);
        
        std::this_thread::sleep_for(duration);
        
        std::string _salary = CONVERT(salary);
        
        File <<  "Salary: ₦" << _salary << std::endl;
        
        std::cout << "Received!\n";
}

int main(){
    
    
    std::string name;
    std::cout << "Enter you name: ";
    getline(std::cin, name);
    
    std::string field;
    std::cout << "What field do you major in? ";
    getline(std::cin, field);
    
    std::string job_title;
    std::cout << "Your job title? ";
    getline(std::cin, job_title);
    
    double salary = Input<double>("The numerical value of your salary? ");
    while(salary < 0){
        std::cout << "Salary cannot be negative!" << std::endl;        
        salary = Input<double>("The numerical value of your salary? ");
    }
    
    std::cout << std::endl;
    
    std::unique_ptr<Job> job = std::make_unique<Job>(field, job_title, salary);
    
    std::unique_ptr<Person> person = std::make_unique<Person>(name, *job);
    person -> description();
    
    PAY(salary);
}