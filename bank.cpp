#include "bank.hpp"
#include <memory>
#include <fstream>

int main() {
    
    //Appending to file.
    std::ofstream File("bank.txt", std::ios::app);
    
    //Reading from file.
    std::ifstream Read("bank.txt");
    std::string last;
    
    if(Read.is_open()){
    std::string lines;
    while(getline(Read, lines)){
        last = lines;
        }
      Read.close();
    }
      double initial = FORMAT(last);
    
      double initial_ = BALANCE(initial);
    
    while (true) {
          std::unique_ptr<std::string> message = std::make_unique<std::string>(Input<std::string>("Welcome to BrumSky Bank, would you like to make a transaction? `yes` or `no`: "));
          
          //First condition.
          if(*message == "yes"){
                 std::unique_ptr<std::string> message_ = std::make_unique<std::string>(Input<std::string>("Options: `dep` for deposit, `wit` for withdraw, and `bor` for borrow: "));  
                 
                       if(*message_ == "dep"){
                             
                             //Pointer for the user to enter the amount that they want to deposit.
        std::unique_ptr<double> wit_dep = std::make_unique<double>(Input<double>("Enter amount: ")); 
       
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
                       
        //Pointer for calculating the user's account balance.
        std::unique_ptr<double> account = std::make_unique<double>(BALANCE(-(*wit_dep_))); 
        
                                   if(*wit_dep_ > *account){
                                          std::cout<<"Cannot do that.\n";                                         
                                          std::unique_ptr<double> account = std::make_unique<double>(BALANCE(*wit_dep_)); 
                                    }    
                                  else{           
                                         //Pointer for converting the user's account balance to a string.
                                        std::unique_ptr<std::string> account_balance = std::make_unique<std::string>(CONVERT(*account));                                              
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
                                std::unique_ptr<double> account = std::make_unique<double>(BALANCE(-(*_wit_dep_)));                
                              //Pointer for converting the user's account balance to a string.
                             std::unique_ptr<std::string> account_balance = std::make_unique<std::string>(CONVERT(*account));         
                               
                             std::cout<<std::endl;  
                               
                             File << std::endl;       
                                    
                             std::cout << "Balance: ₦" << *account_balance << std::endl;     
                             
                             File << "Balance: ₦" << *account_balance << std::endl;   
                             
                             std::cout<<std::endl;
                                                           
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
