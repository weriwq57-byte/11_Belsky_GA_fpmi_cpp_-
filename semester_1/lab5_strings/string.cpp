#include <iostream>
#include <string>
#include <vector>

std::vector <std::string> splitText(std::string &text) {
    std::vector<std::string> words;
    if (text.empty()) {
        return words;
    }
    std::string delimeters = "< .:;!?\t\n\r";
    
    size_t beg_index = 0;
    size_t end_index = text.find_first_of(delimeters, 0);

    while(beg_index != std::string::npos) {
        std::string word;

        if(end_index == std::string::npos) {
            word = text.substr(beg_index);
        }
        else {
            word = text.substr(beg_index, end_index - beg_index);
        }

        if (!word.empty()) {
            words.push_back(word);
        }
        beg_index = text.find_first_not_of(delimeters, end_index);
        if (beg_index != std::string::npos) {
            end_index = text.find_first_of(delimeters, beg_index);
        }
        else {
            break;
        }
    }
    return words;
}

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;
    
    for (int i = 3; i * i <= number; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

bool isNumber(const std::string& str) {
    if (str.empty()) return false;
    
    for (char c : str) {
        if (!std::isdigit(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}


int main() {
    setlocale(LC_ALL, "ru");
    std::string inputText;
    std::cout << "Input text: ";
    std::getline(std::cin, inputText);

    if(inputText.empty()) {
        std::cout << "Error: Empty string entered.\n";
        return 0;
    }
    std::vector<std::string> words = splitText(inputText);
    if(words.empty()) {
    std::cout << "No words found in the text.\n";
    return 0;
    }
    std::vector<std::string> primeWords;
    for (const std::string& word : words) {
        if(isNumber(word)) {
            try{
                long number =std::stol(word);
                if(number > 0 && number <= INT_MAX) {
                    if(isPrime(static_cast<int>(number))) {
                        primeWords.push_back(word);
                    }
                }
            }
            catch (const std::out_of_range& e) {
                continue;
            } catch (const std::invalid_argument& e) {
                continue;
            }
        }
    }   

    if(primeWords.empty()) {
        std::cout << "В тексте не найдено слов, представляющих простые числа." << std::endl;
    }
    else {
        std::string result;
        for (size_t i = 0; i < primeWords.size(); ++i) {
            result += primeWords[i];
            if (i != primeWords.size() - 1) {
                result += " "; 
            }
        }
        std::cout << "Cлова, представляющие простые числа: " << result << std::endl;
    }
    
    return 0;
}