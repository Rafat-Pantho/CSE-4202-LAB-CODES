#include <stdio.h>

size_t StrToNum(const char* str) {
    size_t X = 5381;
    char c;

    while ((c = *str++)) {
        X = X * 33 + c;
    }

    return X;
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);

    // Removing newline character if present
    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }

    size_t result = StrToNum(input);
    printf("%llu\n", result);

    return 0;
}
