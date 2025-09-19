#include <iostream>
#include <string>
#include <cctype>
#include <stddef.h>
#include "include/curl/curl.h"
#include <string.h>
#include <stdlib.h>
// 

void printLine(const std::string& current_line);

int main() {
    
    CURL *curl;
    CURLcode result;
    curl = curl_easy_init();
    if (curl == NULL) {
        std::cout << "NOT GOOD!";
        return -1;
    }
    result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
        fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(result));
        return -1;
    }
    curl_easy_cleanup(curl);
    std::cout << "\n";
    std::cout << result;
    std::string main_word;
    main_word = "BIGGEST";
    char letter;
    // assigning the char "_" to every character in lines:   
    std::string hidden_string;
    hidden_string = "_______";
    
    char temp;
    printLine(hidden_string);
    int index_found;
    bool word_completed;
    word_completed = false;
    while(!word_completed) {
        std::cin >> letter;
        for(int j = 0; j < hidden_string.length(); j++) {
            if(std::toupper(letter) == std::toupper(main_word[j])) {
                hidden_string[j] = std::toupper(letter);
            }
        }
        if(hidden_string == main_word) {
            word_completed = true;
        }    
        printLine(hidden_string);
    }
    std::cout << "Congrats";
    return 0;
}


void printLine(const std::string& current_line) {

    for(int i = 0; i < current_line.size(); i++) {
        std::cout << current_line[i] << " | "; 
    }
    std::cout << "\n\n";
}
