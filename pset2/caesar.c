#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[]) {

  if (argc != 2) {
    printf("Error: Must provide exactly one argument.\n");
    return 1;
  }

  string k = argv[1];
  int key = atoi(k);

  if (key < 1) {
    printf("Error: Key must be a positive integer.\n");
    return 1;
  }

  string unencrypted = GetString();

  for (int i = 0, n = strlen(unencrypted); i < n; i++) {
    if (isalpha(unencrypted[i])) {
      if (islower(unencrypted[i])) {
        char lower_cipher = (((unencrypted[i] - 97) + key) % 26) + 97;
        printf("%c", lower_cipher);
      }
      else {
        char upper_cipher = (((unencrypted[i] - 65) + key) % 26) + 65;
        printf("%c", upper_cipher);
      }
    }
    else {
      printf("%c", unencrypted[i]);
    }
  }
  printf("\n");
}
