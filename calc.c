#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char * get_string(char *string);
double get_digits(char *string);
double to_num(char *string);
double to_num2(char *string);
void replace_sqr(char *string);
// char * get_digits(char *string, double *operand_a);
void removeSpaces(char *str);
double result = 0;

int main(void){
    double op_a = 0;
    char * op_b = NULL;
    char opr = '\0';
    char input[20] = {0};
    char * mystring = NULL;
    int result_trunc = 0;

    puts("Type \"HELP\" or enter a mathematical expression");
    mystring = get_string(input);

    printf("%s%s\n", "This is my string ", mystring) ;
    removeSpaces(mystring);
    replace_sqr(mystring);
    printf("%s%s\n", "This is my string without spaces", mystring) ;

    //result = get_digits(mystring);
    // op_b = get_digits(mystring, &op_a);
    // printf("%s%s\n%s%g\n%s%s\n", "mystring ", mystring, "opa ", op_a, "opb ", op_b);
    op_a = to_num2(mystring);
    if (op_a == trunc(op_a)){
      printf("%s%g\n", "Result = ", op_a);
    } else

    printf("%s%f\n", "Result = ", op_a);


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

double to_num2(char *string) {
  char * string_rem;
  double temp = 0;

  result = strtod(string, &string_rem);




  printf("%gRESULT FIRST\n", result);
  printf("%sSTRING_REM FIRST\n", string_rem);
  while ((*string_rem)) {
    // if (string_rem[0] == '^') {
    //   printf("SQUARED\n");
    //   result = result * result;
    //   string_rem++;
    // }
    if  (string_rem[0] == '#') {
      printf("ROOTED\n");
      result = sqrt(result);
      string_rem++;
    }

    // printf("%sNO_STRING_REM\n", string_rem);
    // return result;

    switch (string_rem[0]) {
      case '+':
        string_rem++;
        string = string_rem;
        temp = strtod(string, &string_rem);
        if (string_rem[0] == '^') {
          temp = temp * temp;
          string_rem++;
        }
        if (string_rem[0] == '#') {
          temp = temp * temp;
          string_rem++;
        }
        //result = result + strtod(string, &string_rem);
        result = result + temp;

        printf("PLUS\n");
      //    return result;
        break;
      case '-':
        string_rem++;
        string = string_rem;
          temp = strtod(string, &string_rem);
        if (string_rem[0] == '^') {
          temp = temp * temp;
          string_rem++;
        }
        if (string_rem[0] == '#') {
          temp = temp * temp;
          string_rem++;
        }

        result = result - temp;

        printf("MINUS\n");
        //return result;
        break;
      case '*':
        string_rem++;
        //temp = to_num(string_rem);
        //printf("%gTEMP, %gRESULT\n", temp, result);
        //result = (result * temp);
        string = string_rem;
        result = result * strtod(string, &string_rem);
        printf("TIMES\n");
      //  return result;
        break;
        case '/':
        string_rem++;
        string = string_rem;
        result = result / strtod(string, &string_rem);
        printf("DIVIDE\n");
        //return result;
        break;
        case '^':
        string_rem++;
        string = string_rem;
        result = result * result;
        printf("SQUARED\n");
        break;
        case '#':
        string_rem++;
        string = string_rem;
        result = sqrt(result);
        printf("ROOTED\n");
        break;
      default:
        break;
    }

  }
  return result;
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
void replace_sqr(char *string) {
  printf("%s%s\n", "String before ", string);
  const char * square = "^";
  const char * root = "#";
  char * temp;
  if (strstr(string, square))
    printf("Found ^\n%s\n", strstr(string, square));


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
