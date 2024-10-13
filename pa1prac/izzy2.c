#include <stdio.h>
#include <stdint.h>
#include <string.h>


int32_t width_from_start_byte(char start_byte) {

    if ((start_byte & 0b11111000) == 0b11110000) {
        return 4;
    }

    if ((start_byte & 0b11110000) == 0b11100000) {
        return 3;
    }

    if ((start_byte & 0b11100000) == 0b11000000) {
        return 2;
    }

    if ((start_byte & 0b11000000) == 0b10000000) {
        return 1;
    }

    return -1;

}

int32_t utf8_strlen(char str[]) {

    int codepoints = 0;
    int i = 0;

    while (str[i] != '\0') {
        int byte_width = width_from_start_byte(str[i]);
        if (byte_width > 1) {
            i += byte_width;
        } else {
            i++;
        }
        codepoints++;
    }                                   

    return codepoints;

}

int32_t codepoint_index_to_byte_index(char str[], int32_t cpi) {

    int bi = 0;
    int idx = 0;

    while(idx < cpi) {

        int byte_len = width_from_start_byte(str[bi]);

        if (byte_len > 1) {
            bi += byte_len;
        } else {
            bi++;
        }
        idx++;
    }

    return bi;
}

void utf8_substring(char str[], int32_t cpi_start, int32_t cpi_end, char result[]) {
    
}

int main(void) {

    char str[] = "Joséph";
    printf("Length of string %s is %d\n", str, utf8_strlen(str));  // 6 codepoints, (even though 7 bytes)

    char str2[] = "éJoséph";
    int32_t idx = 5;
    printf("Codepoint index %d is byte index %d\n", idx, codepoint_index_to_byte_index("éJoséph", idx));

}