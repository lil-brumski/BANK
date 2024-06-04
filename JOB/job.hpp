#ifndef JOB
#define JOB

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>

#include "../bank.hpp"

class Job{  
  protected:
    std::string profession;
    std::string job_title;
    //Per month salary.
    double salary; 
    std::string _salary;
  public:
    Job(std::string p, std::string j, double s): profession(p), job_title(j), salary(s) {}
    
    void job_des(){
        std::cout << "Field: " << profession << std::endl;
        std::cout << "Job Title: " << job_title << std::endl;
        _salary = CONVERT(salary);
        std::cout << "Salary: ₦" << _salary << std::endl;                
        }
        
    };

//class         
class Person{
    protected:
      std::string name;
      Job job;
      
    public:
      Person(std::string n, const Job& j): name(n), job(j) {}
      
      void description(){
          std::cout << "Name: " << name << std::endl;
          job.job_des();
          }
    };
    
#endif