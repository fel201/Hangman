#include <iostream>
#include <ctype.h>
#include <stddef.h>
#include "curl/include/curl/curl.h"
#include <string.h>
#include <stdlib.h>
// 

struct memory {
    char *buffer;
    size_t size;
};
void printLine(const std::string& current_line);
size_t callbackFunction(char *data, size_t size, size_t nmemb, void *userdata);
int main() {
    
    CURL *curl;
    CURLcode result;
    curl = curl_easy_init();
    if (curl == NULL) {
        std::cout << "NOT GOOD!";
        return -1;
    }

    struct memory actual_data = {0};
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callbackFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&actual_data);
    curl_easy_setopt(curl, CURLOPT_URL, "https://random-word-api.herokuapp.com/word");
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    result = curl_easy_perform(curl);

    if (result != CURLE_OK) {
        fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(result));
        return -1;
    }

    curl_easy_cleanup(curl);
    free(actual_data.buffer);
    // the game starts here
    std::cout << "\n";
    char string[128] = {0};
    for(int i = 0; i < actual_data.size; i++) {
        if(actual_data.buffer[i] != '[' && actual_data.buffer[i] != ']'
        && actual_data.buffer[i] != '\"') {
            int j = 0;
            bool space_found = false;
            while (j<128 && !space_found) {
                if (string[j] == '\0') {
                    string[j] = actual_data.buffer[i];
                    space_found = true;
                }
                j++;
            }
        }
    }
    std::cout << string << "\n";
    char *main_word = string;
    char letter;
    // assigning the char "_" to every character in lines:   
    char hidden_string[128] = {0};
    for(int i = 0; i < strlen(main_word); i++) {
        hidden_string[i] += '_';
    }
    char temp;
    printLine(hidden_string);
    int index_found;
    bool word_completed;
    word_completed = false;
    while(!word_completed) {
        std::cin >> letter;
        for(int j = 0; j < strlen(hidden_string); j++) {
            if(tolower(letter) == tolower(main_word[j])) {
                hidden_string[j] = tolower(letter);
            }
        }
        if(strcmp(main_word, hidden_string) == 0) {
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
size_t callbackFunction(char *data, size_t size, size_t nmemb, void *userdata) {
    
    size_t realsize = size*nmemb;
    struct memory *mem = (struct memory*)userdata;
    char *ptr = (char *) realloc(mem->buffer, mem->size + realsize + 1);
    mem->buffer = ptr;
    memcpy(&(mem->buffer[mem->size]), data, realsize);
    mem->size += realsize;
    mem->buffer[mem->size] = 0;
    return realsize;
}