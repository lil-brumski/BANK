#ifndef BANK
#define BANK

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>

   //Wrong Data Type Handler.
    template <class T>
        T Input(const std::string& prompt) {
          T value;
          std::string input;
         while (true) {
            std::cout << prompt;
            std::getline(std::cin, input);
            std::istringstream stream(input);
            if (stream >> value && stream.eof()) {
                 break;
            } else {
                 std::cerr << "Wrong data type, try again!\n";
              }
        }
        return value;
     }


std::string CONVERT(double value){
    // Create an output string stream
    std::ostringstream oss;
    // Set fixed format and precision to 2 decimal places
    oss << std::fixed << std::setprecision(0) << value;
    // Convert the stream to a string
    std::string str = oss.str();

   if(str.length() >= 4 && str.length() <= 9){
             if(str.length() == 4){
                 str.insert(1, ",");
                 }
             else if(str.length() == 5){
                 str.insert(2, ",");
                 }
             else if(str.length() == 6){
                 str.insert(3, ",");
                 }
             else if(str.length() == 7){
                 str.insert(1, ",");
                 str.insert(5, ",");
                 }
             else if(str.length() == 8){
                 str.insert(2, ",");
                 str.insert(6, ",");
                 }
             else if(str.length() == 9){
                 str.insert(3, ",");
                 str.insert(7, ",");
                 }
       }
       
   else if(str.length() >= 10 && str.length() <= 12){
             if(str.length() == 10){
                 str.insert(1, ",");
                 str.insert(5, ",");
                 str.insert(9, ",");
                 }
             else if(str.length() == 11){
                 str.insert(2, ",");
                 str.insert(6, ",");
                 str.insert(10, ",");
                 }
             else if(str.length() == 12){
                 str.insert(3, ",");
                 str.insert(7, ",");
                 str.insert(11, ",");
                 }
    }  
    
    return str;    
}
  
              
double REMOVE(std::string value){
    char charToRemove = ',';
    
    value.erase(std::remove(value.begin(), value.end(), charToRemove), value.end());
        
    return std::stod(value);
}


double FORMAT(std::string value){   
  
    std::string cleanedValue;
    if(!value.empty()){
         for(int x = 0; x < value.length(); x++){
               if(std::isdigit(value[x])){
               cleanedValue += value[x];
               }
         }
      
    }
    else{
        cleanedValue = "0";
    }
           
    return std::stod(cleanedValue);
}


double BALANCE(double cash){
    static double balance = 0;
    balance += cash;
    balance = std::round(balance);
std::cout<<std::fixed<<std::setprecision(2)<<std::endl;
    return balance;
}
#endif