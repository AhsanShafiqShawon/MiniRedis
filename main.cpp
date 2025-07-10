#include <iostream>
#include <sstream>
#include <vector>
#include "redis.h"

std::vector<std::string> split(const std::string& line) {
    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::string word;
    while(iss >> word) tokens.push_back(word);
    return tokens;
}

int main() {
    Redis redis;
    std::string line;

    std::cout << "MiniRedis started. Type commands or 'EXIT' to quit.\n";

    while(true) {
        std::cout << "redis> ";
        std::getline(std::cin, line);
        auto tokens = split(line);
        if(tokens.empty()) continue;

        std::string cmd = tokens[0];

        if(cmd == "EXIT" || cmd == "QUIT") break;
        else if(cmd == "SET" && tokens.size() == 3)
            redis.set(tokens[1], tokens[2]);
        else if(cmd == "GET" && tokens.size() == 2)
            std::cout << redis.get(tokens[1]) << "\n";
        else if(cmd == "DEL" && tokens.size() == 2)
            std::cout << (redis.del(tokens[1]) ? "OK" : "(nil)") << "\n";
        else 
            std::cout << "ERR unknown or invalid command\n";
    }

    std::cout << "Bye\n";
    return 0;
}
