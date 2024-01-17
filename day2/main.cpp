#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int getId(std::string& line, char delim){
    std::string temp;

    int i = 2;
    for(char c : line){
        if(c == delim)
            break;
        temp += c;
        i++;
    }
    line.erase(line.begin(), line.begin() + i);
    return stoi(temp);
}

std::vector<std::string> splitSet(std::string& line, char delim){
    int cnt = 0;
    std::string tracker = "";
    char current;

    std::vector<std::string> data = std::vector<std::string>();

    while(1){
        current = line[cnt++];
        if(current == delim){
            data.push_back(tracker);
            tracker.clear();
            cnt += 1;
        }else if(current == '\0'){
            data.push_back(tracker);
            break;
        }else tracker += current;
    }

    return data;
}

bool validGame(std::string& set, char delim){

    std::string temp = "";
    std::string val = "";
    int cnt = 0;

    while(1){
        char c = set[cnt++];
        if(c == delim){
            std::cout << temp << "\n";
            cnt += 1;
            temp.clear();
        }
        else if(cnt >= set.length() - 1){
            break;
        }
        else{
             temp += c;
        }
    }



    return false;
}

int resultPartOne(){
    std::ifstream file("input1.txt");
    std::string line;

    const int redCubeLimit = 12;
    const int greenCubeLimit = 13;
    const int blueCubeLimit = 14;

    int gameId = 0;

    while(getline(file, line)){
        line.erase(line.begin(), line.begin() + 5);
        gameId = getId(line, ':');
        std::vector<std::string> gameSet = splitSet(line, ';');

        for(std::string set : gameSet){
            validGame(set, ',');
        }
    }

    return 0;
}

int main(){
    
    return resultPartOne();
}