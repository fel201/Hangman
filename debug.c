#include <stdio.h>
#include <string.h>

int main(void) {
    char string[128] = {0};
    char actual_data[128] = "\"[Hey\"]";

    for(int i = 0; i < strlen(actual_data); i++) {
        if(actual_data[i] != '[' && actual_data[i] != ']'
        && actual_data[i] != '\"') {
            int j = 0;
            int space_found = 0;
            while (j<128 && !space_found) {
                printf("something");
                if (string[j] == '\0') {
                    string[j] = actual_data[i];
                    space_found = 1;
                }
                j++;
            }
        }
    }
    
}