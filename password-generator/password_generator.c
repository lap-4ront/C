#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


int main()
{
  printf("Length: ");

  int length;
  scanf("%d", &length);

  if(length <= 0)
  {
    printf("Password length must be >= 1");
    return 1;
  }

  char *password = malloc(length + 1);

  free(password);

  // this will work in modern C (interchanges lines :17 and :19)
  // char password[length + 1];

  char *digits = "0123456789";
  int digits_length = strlen(digits);

  char *lowers = "abcdefghijklmnopqrstuvwxyz";
  int lowers_length = strlen(lowers);

  char *uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int uppers_length = strlen(uppers);

  char *symbols = "!@#$%^&*()";
  int symbols_length = strlen(symbols);

  srand(time(NULL) * getpid()); //form random hash with current time and process pid

  for(int i = 0; i < length; i++)
  {
    int char_type = rand() % 4;

    if(char_type == 0)
      password[i] = digits[rand() % digits_length]; // random character in digits
    else if(char_type == 1)
      password[i] = lowers[rand() % lowers_length]; // random character in lowers
    else if(char_type == 2)
      password[i] = uppers[rand() % uppers_length]; // random character in uppers
    else
      password[i] = symbols[rand() % symbols_length]; // random character in symbols
   }

  password[length] = '\0';

  printf("Password: %s\n", password);

  return 0;
}
