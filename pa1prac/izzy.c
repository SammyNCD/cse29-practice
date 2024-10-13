#include <stdio.h>
#include <stdint.h>
#include <string.h>


int32_t is_ascii(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if ((str[i] & 128) == 128) {
            return 0;
        }
    }
    return 1;
}

int32_t capitalize_ascii(char str[]) {
    int len = strlen(str);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
            count++;
        }
    }
    return count;
}

int main(void) {
    printf("Is 🔥 ASCII? %d\n", is_ascii("🔥"));
    
    int32_t ret = 0;
    char str[] = "abcd";
    ret = capitalize_ascii(str);
    printf("Capitalized String: %s\nCharacters updated: %d\n", str, ret);

}