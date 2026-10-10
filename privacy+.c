#include <stdio.h>
#include <string.h>

int main()
{
    char message[41] = "0";
    int comand_choice;
    printf("=========================================\n");
    printf("1 for encryption.\n2 for decryption.\n");
    printf("ENTER YOUR COUMAND [1 OR 2]: ");
    scanf("%d", &comand_choice);

    while (getchar() != '\n')
        ;

    if (comand_choice == 1) // encrypting message
    {

        printf("enter message to encrypt: ");
        if (fgets(message, sizeof(message), stdin) != NULL)
        {
            int len = strlen(message);
            if (len > 0 && message[len - 1] == '\n')
            {
                message[len - 1] = '\0';
            }
        }
        printf("-------------------------------------------\n");
        printf("ENCRYPTED MESSAGE:");
        int len = strlen(message);
        for (int i = 0; i < len; i++)
        {
            int q = 32 + (6 * (int)message[i] + 94) % 95; // like Affine

            printf("%c", (char)q);
        }
        printf("\n-------------------------------------------\n");
    }

    else if (comand_choice == 2) // decrepting message
    {
        printf("enter encrypted message: ");
        if (fgets(message, sizeof(message), stdin) != NULL)
        {
            int len = strlen(message);
            if (len > 0 && message[len - 1] == '\n')
            {
                message[len - 1] = '\0';
            }
        }
        printf("-------------------------------------------\n");
        printf("DECRYPTED MESSAGE:");
        int len = strlen(message);
        for (int i = 0; i < len; i++)
        {
            // decrypting equaiton.
            int y = (int)message[i] - 32;

            int decrypted_val = (16 * (y + 1)) % 95;

            if (decrypted_val < 32)
            {
                decrypted_val += 95;
            }

            // 4. Output the decrypted character
            printf("%c", (char)decrypted_val);
        }
        printf("\n-------------------------------------------\n");
    }

    else
    {
        printf("INVALID COMAND!!");
    }

    printf("\n\n");

    return 0;
}