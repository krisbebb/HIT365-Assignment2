#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char * get_string(char *string);
double get_digits(char *string);
// char * get_digits(char *string, double *operand_a);
void removeSpaces(char *str);
double result = 0;

int main(void){
    double op_a = 0;
    char * op_b = NULL;
    char opr = '\0';
    char input[20] = {0};
    char * mystring = NULL;

    puts("Type \"HELP\" or enter a mathematical expression");
    mystring = get_string(input);

    printf("%s%s\n", "This is my string ", mystring) ;
    removeSpaces(mystring);
    printf("%s%s\n", "This is my string without spaces", mystring) ;

    result = get_digits(mystring);
    // op_b = get_digits(mystring, &op_a);
    // printf("%s%s\n%s%g\n%s%s\n", "mystring ", mystring, "opa ", op_a, "opb ", op_b);


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
  string += '\0';
  return string;
}


double get_digits(char *string) {
  char *partb;
  char *operand_a;
  char *digits;
  double parta;

  parta = strtod(string, &partb);




    if (*partb != '\0') {
        printf("%s is the string part\n", partb);
    } else {
      printf("No string part\n");
    }

    //*operand_a = parta;
    result += parta;

    switch (partb[0]){
      case '+':

      partb++;
      printf("%g PLUS %s\n", parta, partb);
      result += get_digits(partb);
      printf("%g result\n", result);
        break;
      default :
    break;
    }

  return result;
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
