#include <stdio.h>

int main() {
    int p, g, a, b;
    int A, B, key1, key2;

    printf("Enter prime number p: ");
    scanf("%d", &p);

    printf("Enter primitive root g: ");
    scanf("%d", &g);

    printf("Enter private key of Alice: ");
    scanf("%d", &a);

    printf("Enter private key of Bob: ");
    scanf("%d", &b);

    // Alice's public key
    A = 1;
    for (int i = 0; i < a; i++)
        A = (A * g) % p;

    // Bob's public key
    B = 1;
    for (int i = 0; i < b; i++)
        B = (B * g) % p;

    // Shared secret key
    key1 = 1;
    for (int i = 0; i < b; i++)
        key1 = (key1 * A) % p;

    key2 = 1;
    for (int i = 0; i < a; i++)
        key2 = (key2 * B) % p;

    printf("\nAlice's Public Key = %d", A);
    printf("\nBob's Public Key   = %d", B);
    printf("\nAlice's Secret Key  = %d", key1);
    printf("\nBob's Secret Key    = %d\n", key2);

    return 0;
}
