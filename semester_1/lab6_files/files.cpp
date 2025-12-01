#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
        
        
        int current_length = 1;
        int max_length = line.empty() ? 0 : 1;
        
        for(size_t i = 1; i < line.size(); i++) {
            if(line[i] > line[i-1]) {
                current_length++;
                if(current_length > max_length) {
                    max_length = current_length;
                }
            }
            else {
                current_length = 1;
            }
        }
        max_lenghs.push_back(max_length);

        if (global_max < max_length) {
            global_max = max_length;
        }
       

    }

  
    
    input.close();
    std::cout << "Строки с максимальной длиной возрастающей подстроки (" 
              << global_max << "):\n";
    std::cout << "=========================================\n";
    
    int count = 0;
    for (size_t i = 0; i < all_lines.size() && count < 10; i++) {
        if (max_lenghs[i] == global_max) {
            std::cout << "Строка " << (i + 1) << ": \"" 
                      << all_lines[i] << "\"\n";
            count++;
        }
    }
    
    if (count == 0) {
        std::cout << "Таких строк не найдено.\n";
    }

    return 0;
}