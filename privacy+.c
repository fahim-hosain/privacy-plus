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
    while (1)
    {

        char message[41] = "0";
        int command_choice;
        printf("=========================================\n");
        printf("WELCOME TO THE ENCRYPTION/DECRYPTION PROGRAM\n");
        printf("1-> Encrypt message\n");
        printf("2-> Decrypt message\n");
        printf("3-> Encrypt file (only .txt files)\n");
        printf("4-> Decrypt file (only .txt files)\n");
        printf("5-> exit\n");
        printf("=========================================\n");
        printf("ENTER YOUR COMMAND [1 to 4]: ");
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
        else if (command_choice == 3) // encrypting file
        {
            FILE *fptr;
            FILE *fptr2;
            char string_data[250];
            char filename[31];
            char prefix[11] = "encrypted_";
            char combined[42];
            printf("[file name must be less than 31 characters]\nenter file name: ");

            if (fgets(filename, sizeof(filename) / sizeof(filename[0]), stdin) != NULL)
            {
                int last_index = strcspn(filename, "\n");
                filename[last_index] = '\0';
            }
            printf("-----------------------------------------------\n");
            fptr = fopen(filename, "r");
            if (fptr == NULL)
            {
                printf("Error! opening file");
                return 1;
            }

            snprintf(combined, sizeof(combined), "%s%s", prefix, filename);
            fptr2 = fopen(combined, "w");
            if (fptr2 == NULL)
            {
                printf("Error! opening file");
                return 1;
            }

            while (fgets(string_data, sizeof(string_data) / sizeof(string_data[0]), fptr) != NULL)
            {
                // Remove the trailing newline so it doesn't get encrypted
                string_data[strcspn(string_data, "\r\n")] = '\0';

                apply_encryption(string_data, strlen(string_data));
                fprintf(fptr2, "%s", string_data);
                fprintf(fptr2, "\n");
            }
            printf("File encrypted successfully. Encrypted file name: %s\n", combined);
            printf("-----------------------------------------------\n");

            fclose(fptr);
            fclose(fptr2);
        }
        else if (command_choice == 4) // decrypting file
        {
            FILE *fptr;
            FILE *fptr2;
            char string_data[250];
            char filename[31];
            char prefix[11] = "decrypted_";
            char combined[42];
            printf("[file name must be less than 31 characters]\nenter file name: ");

            if (fgets(filename, sizeof(filename) / sizeof(filename[0]), stdin) != NULL)
            {

                int last_index = strcspn(filename, "\n");
                filename[last_index] = '\0';
            }

            printf("-----------------------------------------------\n");
            fptr = fopen(filename, "r");
            if (fptr == NULL)
            {
                printf("Error! opening file");
                return 1;
            }

            char *target_prefix = "encrypted_";
            int prefix_len = strlen(target_prefix);

            if (strncmp(filename, target_prefix, prefix_len) == 0)
            {
                // Shift the rest of the string to the beginning, deleting "encrypted_"
                memmove(filename, filename + prefix_len, strlen(filename) - prefix_len + 1);
            }

            snprintf(combined, sizeof(combined), "%s%s", prefix, filename);
            fptr2 = fopen(combined, "w");
            if (fptr2 == NULL)
            {
                printf("Error! opening file");
                return 1;
            }

            while (fgets(string_data, sizeof(string_data) / sizeof(string_data[0]), fptr) != NULL)
            {
                // Remove the trailing newline so it doesn't get encrypted
                string_data[strcspn(string_data, "\r\n")] = '\0';

                apply_decryption(string_data, strlen(string_data));
                fprintf(fptr2, "%s", string_data);
                fprintf(fptr2, "\n");
            }
            printf("File decrypted successfully. Decrypted file name: %s\n", combined);
            printf("-----------------------------------------------\n");

            fclose(fptr);
            fclose(fptr2);
        }
        else if (command_choice == 5)
        {
            break;
        }

        else
        {
            printf("INVALID COMMAND!!");
        }

        printf("\n");

        return 0;
    }
}