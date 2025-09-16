#include <iostream>
#include <string>

// 
void printLine(char *current_line);

int main() {
    std::string main_word;
    main_word = "Biggest";
    char letter;
    // assigning the char "_" to every character in lines:   
    char line[] = "_______";
    
    char temp;
    printLine(line);
    
    for(int i = 0; i < sizeof(line)-1; i++) {
        std::cout<<"\n\n";
        std::cin >> temp;
        std::cout<<"\n\n";
        line[i] = temp;
        printLine(line);
    }

}



void printLine(char *current_line) {

    for(int i = 0; i < sizeof(current_line)-1; i++) {
        std::cout << current_line[i] << " | "; 
    }
    std::cout << "\n\n";
}