#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

std::vector<std::string> split(std::string &str, char delim){
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while(getline(ss, token, delim)){
        result.push_back(token);
    }
    return result;
}

void trim(std::string &str){
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

bool isValid(std::string& game){
    std::vector<std::string> splitGame = split(game, ' ');

    std::string tempValue = splitGame[1];
    
    int value = std::stoi(tempValue);
    std::string color = splitGame[2];

    if(color == "red" && value <= MAX_RED){ return true; }
    else if(color == "green" && value <= MAX_GREEN){ return true; }
    else if(color == "blue" && value <= MAX_BLUE){ return true; }
    else return false;
}

int resultPartOne(){
    std::string line, number;
    std::ifstream file("input1.txt");

    int result = 0;

    bool count;
    int sum = 0;
    while(getline(file, line)){
        count = true;
        std::vector<std::string> result = split(line, ':');
        int gameID = std::stoi(split(result[0], ' ')[1]);
        std::string splitLine = result[1];

        std::vector<std::string> gameSets = split(splitLine, ';');
        for(std::string set : gameSets){
            std::vector<std::string> game = split(set, ',');
            for(std::string s : game){
                bool valid = isValid(s);
                if(!valid){
                    count = false;
                    break;
                }
            }
            if(!count){
                break;
            }
        }
        if(count)
            sum += gameID;
        
    }
    file.close();
    return sum;
}


int main(){
    std::cout << "Part one: " << resultPartOne() << std::endl;

}