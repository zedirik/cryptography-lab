#include <stdio.h>

int main() {
    char text[100], enc[100], dec[100];
    int key[2][2], inv[2][2];
    int i, a, b, det, det_inv;

    printf("Enter text (even number of letters): ");
    scanf("%s", text);

    printf("Enter 2x2 key matrix:\n");
    for (i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &key[i][j]);

    // Determinant
    det = key[0][0] * key[1][1] - key[0][1] * key[1][0];

    // Find inverse of determinant
    for (i = 1; i < 26; i++) {
        if ((det * i) % 26 == 1) {
            det_inv = i;
            break;
        }
    }

    // Inverse matrix
    inv[0][0] = key[1][1] * det_inv % 26;
    inv[0][1] = -key[0][1] * det_inv % 26;
    inv[1][0] = -key[1][0] * det_inv % 26;
    inv[1][1] = key[0][0] * det_inv % 26;

    // Encryption
    for (i = 0; text[i] != '\0'; i += 2) {
        a = text[i] - 'A';
        b = text[i + 1] - 'A';

        enc[i] = (key[0][0] * a + key[0][1] * b) % 26 + 'A';
        enc[i + 1] = (key[1][0] * a + key[1][1] * b) % 26 + 'A';
    }
    enc[i] = '\0';

    // Decryption
    for (i = 0; enc[i] != '\0'; i += 2) {
        a = enc[i] - 'A';
        b = enc[i + 1] - 'A';

        dec[i] = (inv[0][0] * a + inv[0][1] * b) % 26 + 'A';
        dec[i + 1] = (inv[1][0] * a + inv[1][1] * b) % 26 + 'A';
    }
    dec[i] = '\0';

    printf("Encrypted: %s\n", enc);
    printf("Decrypted: %s\n", dec);

    return 0;
}
