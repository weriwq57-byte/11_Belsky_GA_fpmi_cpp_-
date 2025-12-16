#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

int findMaxIncreasLength(const std::string& str) {
    if (str.empty()) return 0;
    
    int maxLength = 1;
    int currentLength = 1;

    for (size_t i = 1; i < str.size(); i++) {
        if (str[i] > str[i - 1]) {
            currentLength++;
            if (currentLength > maxLength) { 
                maxLength = currentLength;
            }
        } else {
            currentLength = 1;
        }
    }  
    return maxLength;
}

void printRes(const std::vector<std::string>& lines, const std::vector<int>& maxLengths, int globalMax) {
    
    std::cout << "Строки с максимальной длиной возрастающей подстроки (" << globalMax << "):\n";
    std::cout << "=========================================\n";
    
    int count = 0;

    for (size_t i = 0; i < lines.size() && count < 10; i++) {
        if (maxLengths[i] == globalMax) {
            std::cout << "Строка " << (i + 1) << ": \"" 
                      << lines[i] << "\" " << std::endl;
            count++;
        }
    }
    
    if (count == 0) {
        std::cout << "Строки не найдены\n";
    } else {
        std::cout << "\nНайдено строк: " << count << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cout << "Файл input.txt не найден.\n";
        return 1;
    }
    std::string first_line;
    if(!getline(input, first_line)) {
        std::cout << "Файл input.txt пуст.\n";
        return 1; 
    }
    input.seekg(0);
    std::vector <std::string> all_lines;
    std::vector <int> max_lenghs;
    int global_max = 0;
    
    std::string line;
    while(getline(input, line)) {
        all_lines.push_back(line);
        
        int max_length = findMaxIncreasLength(line);
        max_lenghs.push_back(max_length);

        if (global_max < max_length) {
            global_max = max_length;
        }
    }
  
    input.close();
    printRes(all_lines, max_lenghs, global_max);
    return 0;
}