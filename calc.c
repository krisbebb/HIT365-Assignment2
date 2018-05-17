#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char * get_string(char *string);
char * get_digits(char *string, double *operand);
void removeSpaces(char *str);

int main(void){
    double operand_a = 0;
    double operand_b = 0;
    char operator = '\0';
    char input[20] = {0};
    char * mystring = NULL;

    puts("Type \"HELP\" or enter a mathematical expression");
    mystring = get_string(input);

    printf("%s%s\n", "This is my string ", mystring) ;
    removeSpaces(mystring);
    printf("%s%s\n", "This is my string without spaces", mystring) ;

    get_digits(mystring, &operand_a);

}
char * get_string(char *string) {

  // sscanf("%s", string);
  // printf("%s\n", string);
  //
  // removeSpaces(string);
  // string = "";
  char c = getchar();

  size_t i=0;
  string[i] = c;

  while (c!='\n'){

    string[i] = c;

    i++;
    c=getchar();

  }
  return string;
}
char  * get_digits(char *string, double *operand) {
  // size_t i = 0;
  // size_t ln = strlen(string);
  // size_t j = 0;
  // char digits[20] = {0};
  // double operand_a = 0;
  // printf("strlen is %lu\n", ln);
  // while (string[i] != '\0' && string[i] !='\n') {
  //   //putchar(string[i]);
  //   if (isdigit((string[i]))){
  //     printf("%c is a digit\n", string[i]);
  //     digits[j] = string[i];
  //     j++;
  //   } else {
  //     printf("%c not a digit\n", string[i]);
  //   }
  //   i++;
  // }
  //
  // printf("%s%s\n", "*digits is ", digits);
  // operand_a = strtod("99.0");
  // printf("Operand a is %f", operand_a);
  // return operand_a;

  char *ptr;
  double digits;
  double ret;
  ret = strtod(string, &ptr);
  printf("%g is the number\n", ret);
  // size_t i=0;
  // while (!ptr[i]) {
  //   printf("%s%c\n", "ptr is", ptr[i]);
  //   i++;
  // }
  // for (i = 0; i <= strlen(ptr); i++) {
  //     printf("%s%c", " ptr char ", ptr[i]);
  // }



  printf("%s is the string part\n", ptr);
  *operand = ret;
  return ptr;
}
void removeSpaces(char *str)
{
    // To keep track of non-space character count
    int count = 0;

    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i]; // here count is
                                   // incremented
    str[count] = '\0';
  }
