#include <stdio.h>

int romanCharToInt(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char *s) {
    int result = 0;
    int current, next;

    while (*s) {
        current = romanCharToInt(*s);
        next = romanCharToInt(*(s+1));

        if (current < next) {
            result += (next - current);
            s += 2;
        } else {
            result += current;
            s++;
        }
    }

    return result;
}