#include "bank.hpp"
#include <memory>
#include <fstream>

int main() {
    
    //Appending to file.
    std::ofstream File("bank.db", std::ios::app);
    
    //Reading from bank.db file.
    std::ifstream Read("bank.db");
    std::string last;
    
    if(Read.is_open()){
    std::string lines;
    while(getline(Read, lines)){
        last = lines;
        }
      Read.close();
    }
    //Converts the last line of the bank.db file to numeric values.
      double initial = FORMAT(last);
       //Takes the double above and makes it the user's account balance.
      double initial_ = BALANCE(initial);
      
      
    //Read from salary.db file in JOB directory.
    std::ifstream Job("JOB/salary.db");
    std::string collect;
    
    if(Job.is_open()){
    std::string dis;
    while(getline(Job, dis)){
        collect = dis;
        }
      Job.close();
    }
    //Converts the last line of salary.db to a numerical value.
    double salary = FORMAT(collect);
    //Adds the value gotten in "salary" to the user's account balance.
    double payment = BALANCE(salary);
    
    
    
    while (true) {
          std::unique_ptr<std::string> message = std::make_unique<std::string>(Input<std::string>("Welcome to BrumSky Bank, would you like to make a transaction? `yes` or `no`: "));
          
          //First condition.
          if(*message == "yes"){
                 std::unique_ptr<std::string> message_ = std::make_unique<std::string>(Input<std::string>("Options: `dep` for deposit, `wit` for withdraw, `bal` for account balance, and `bor` for borrow: "));  
                 
                       if(*message_ == "dep"){
                             
                             //Pointer for the user to enter the amount that they want to deposit.
        std::unique_ptr<double> wit_dep = std::make_unique<double>(Input<double>("Enter amount: ")); 
       
       //Makes sure the user doesn't enter a value less than 1.
       while(*wit_dep < 1){
           std::cout<<"Cannot deposit that amount!\n";
           wit_dep = std::make_unique<double>(Input<double>("Enter amount: ")); 
       }
       
        //Pointer for calculating the user's account balance.
        std::unique_ptr<double> account = std::make_unique<double>(BALANCE(*wit_dep));     
                   
        //Pointer for converting the user's account balance to a string.
        std::unique_ptr<std::string> account_balance = std::make_unique<std::string>(CONVERT(*account));  
                 
        std::cout<<std::endl;  
        
        File << std::endl;
                     
        File<<"Balance: ₦" << *account_balance << std::endl;       
        
        std::cout << "Balance: ₦" << *account_balance << std::endl;    
            
        std::cout<<std::endl;
                           }
                           
                       else if(*message_ == "wit"){
                           //Pointer for the user to enter the amount that they want to deposit.
                          std::unique_ptr<double> wit_dep_ = std::make_unique<double>(Input<double>("Enter amount: "));           
         
                         double qwerty = BALANCE(0);          
                                
                                   if(*wit_dep_ > qwerty){
                                          std::cout<<"Cannot withdraw more than account balance! Put funds first.\n";                                                                    
                                    }    
                                  else{         
                                           //Pointer for calculating the user's account balance .
                         std::unique_ptr<double> account_ = std::make_unique<double>(BALANCE(-(*wit_dep_)));   
                                         //Pointer for converting the user's account balance to a string.
                                        std::unique_ptr<std::string> account_balance = std::make_unique<std::string>(CONVERT(*account_));                                              
                                        std::cout<<std::endl; 
                                        File<<std::endl;           
                                        std::cout << "Balance: ₦" << *account_balance << std::endl;    
                                        File<< "Balance: ₦" << *account_balance << std::endl;   
                                         std::cout<<std::endl;          
                                  }
                           }
                           
                       else if(*message_ == "bor"){
                                 //Pointer for the user to enter the amount that they want to deposit.
                                std::unique_ptr<double> _wit_dep_ = std::make_unique<double>(Input<double>("Enter amount: "));     
                                //Pointer for calculating the user's account balance.
                                std::unique_ptr<double> _account_ = std::make_unique<double>(BALANCE(-(*_wit_dep_)));                
                              //Pointer for converting the user's account balance to a string.
                             std::unique_ptr<std::string> account_balance = std::make_unique<std::string>(CONVERT(*_account_));         
                               
                             std::cout<<std::endl;  
                               
                             File << std::endl;       
                                    
                             std::cout << "Balance: ₦" << *account_balance << std::endl;     
                             
                             File << "Balance: ₦" << *account_balance << std::endl;   
                             
                             std::cout<<std::endl;
                                                           
                           }
                           
                           
                       else if(*message_ == "bal"){
                            double check = BALANCE(0);
                            
                            std::string _check = CONVERT(check);
                            
                            std::cout<<std::endl;  
                              
                            std::cout<<"Balance: ₦"<<_check<<std::endl;
                            
                            File << std::endl;     
                            
                            File << "Balance: ₦" << _check << std::endl;                    
                         
                          }     
                           
                           
                       else{
                               std::cout<<"Wrong input. Try again.\n";                   
                             }                                                       
              }
                            
              
   else if(*message == "no"){
              
              std::cout<<"Goodbye!\n";              
                          
              return 0;
     }
              
                            
     else{
              
              std::cout<<"Wrong input!\n";              
              
              }
          
        
        // Memory will be automatically released when smart pointers go out of scope
    }

    return 0;
}