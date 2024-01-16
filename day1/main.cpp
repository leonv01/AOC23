#include <iostream>
#include <fstream>
#include <string>

int resultPartOne(){
    std::string line, number;
    std::ifstream file("input1.txt");
    int result = 0;
    while(getline(file, line)){
        number = "";

        for(char c : line){
            if(c >= '0' && c <= '9'){
                number += c;
            }
        }

        if(number.length() >= 2){
            std::string temp = "";
            temp += number[0];
            temp += number[number.length() - 1];
            number = temp;
        }
        else{
            number += number;
        }
        result += std::stoi(number);
    }
    file.close();
    return result;
}

int resultPartTwo(){
    std::string line, number;
    std::ifstream file("input1.txt");



    int result = 0;

    while(getline(file, line)){
        number = "";
        std::cout << line << "\n";
    }

    file.close();
    return result;
}

int main(){
    std::cout << "Part one: " << resultPartOne() << std::endl;
   // std::cout << "Part two: " << resultPartTwo() << std::endl;

}