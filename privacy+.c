#include <stdio.h>
#include <string.h>

void apply_encryption(char *message, int size) // encryption function
{
    for (int i = 0; i < size; i++)
    {
        int q = 32 + (6 * (int)message[i] + 94) % 95;
        message[i] = (char)q;
    }
}

void apply_decryption(char *message, int size) // decryption function
{
    for (int i = 0; i < size; i++)
    {
        int x = (int)message[i] - 32;
        int decrypted_val = (16 * (x + 1)) % 95;
        if (decrypted_val < 32)
        {
            decrypted_val += 95;
        }

        message[i] = (char)decrypted_val;
    }
}

int main()
{
    char message[41] = "0";
    int command_choice;
    printf("=========================================\n");
    printf("1 for encryption.\n2 for decryption.\n");
    printf("ENTER YOUR COMMAND [1 OR 2]: ");
    scanf("%d", &command_choice);

    while (getchar() != '\n')
        ;

    if (command_choice == 1) // encrypting message
    {

        printf("enter message to encrypt: ");
        if (fgets(message, sizeof(message) / sizeof(message[0]), stdin) != NULL)
        {
            int last_index = strcspn(message, "\n"); // find the new line character
            message[last_index] = '\0';              // replaces the new line character with nul terminator
        }
        printf("-------------------------------------------\n");
        printf("ENCRYPTED MESSAGE:");
        int length = strlen(message);

        apply_encryption(message, length);
        printf("%s", message);

        printf("\n-------------------------------------------\n");
    }

    else if (command_choice == 2) // decrypting message
    {
        printf("enter encrypted message: ");
        if (fgets(message, sizeof(message) / sizeof(message[0]), stdin) != NULL)
        {
            int last_index = strcspn(message, "\n"); // finds the new line character
            message[last_index] = '\0';              // replaces the new line character with nul terminator
        }
        printf("-------------------------------------------\n");
        printf("DECRYPTED MESSAGE:");
        int length = strlen(message);

        apply_decryption(message, length);
        printf("%s", message);

        printf("\n-------------------------------------------\n");
    }

    else
    {
        printf("INVALID COMMAND!!");
    }

    printf("\n\n");

    return 0;
}