#include <stdio.h>

int main() {
    char text[100], key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char enc[100], dec[100];
    int i, j;

    printf("Enter text: ");
    fgets(text, 100, stdin);

    // Encryption
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            enc[i] = key[text[i] - 'A'];
        else if (text[i] >= 'a' && text[i] <= 'z')
            enc[i] = key[text[i] - 'a'] + 32;
        else
            enc[i] = text[i];
    }
    enc[i] = '\0';

    // Decryption
    for (i = 0; enc[i] != '\0'; i++) {
        if (enc[i] >= 'A' && enc[i] <= 'Z') {
            for (j = 0; j < 26; j++)
                if (key[j] == enc[i])
                    dec[i] = 'A' + j;
        }
        else if (enc[i] >= 'a' && enc[i] <= 'z') {
            for (j = 0; j < 26; j++)
                if (key[j] + 32 == enc[i])
                    dec[i] = 'a' + j;
        }
        else
            dec[i] = enc[i];
    }
    dec[i] = '\0';

    printf("Encrypted: %s", enc);
    printf("Decrypted: %s", dec);

    return 0;
}
