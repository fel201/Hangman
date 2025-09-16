#include <iostream>
#include <string>

// 
void printLine(char *current_line);

int main() {
    std::string main_word;
    main_word = "Biggest";
    char letter;
    // assigning the char "_" to every character in lines:   
    char hidden_string[] = "_______";
    
    char temp;
    printLine(hidden_string);
    int index_found;
    for(int i = 0; i < sizeof(hidden_string)-1; i++) {
        std::cin >> letter;
        for(int j = 0; j < sizeof(main_word)-1; j++) {
            if(letter == main_word[j]) {
                hidden_string[j] = letter;
            }
        }    
        printLine(hidden_string);
    }
    return 0;
}

void printLine(char *current_line) {

    for(int i = 0; i < sizeof(current_line)-1; i++) {
        std::cout << current_line[i] << " | "; 
    }
    std::cout << "\n\n";
}

