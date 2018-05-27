#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char * get_string(char *string);
double to_num2(char *string);
void replace_sqr(char *string);
void removeSpaces(char *str);
void prompt(void);
void reset(void);
int eval_input(char *string);
void print_help(void);
void print_answer();

double answer = 0;
char input[20] = {0};
char * calc_string = NULL;
int result_trunc = 0;
int exit_calc = 0;
double memory = 0;

int main(void){
  printf("memory is equal to %g\n", memory);
  reset();
  while (!exit_calc){
printf("memory is equal to %g\n", memory);
    prompt();


    printf("%s%s\n", "This is my string ", calc_string) ;
    removeSpaces(calc_string);
    replace_sqr(calc_string);
    printf("%s%s\n", "This is my string without spaces", calc_string) ;
    eval_input(calc_string);




} // end while
}
char * get_string(char *string) {

  // sscanf("%s", string);
  // printf("%s\n", string);
  //
  // removeSpaces(string);

  char c = getchar();

  size_t i=0;
  string[i] = c;

  while (c!='\n'){

    string[i] = c;

    i++;
    c=getchar();

  }
  string[i] = '\0';
  return string;
}

double to_num2(char *string) {
  printf("memory is equal to %g\n", memory);
  char * string_rem;
  double temp = answer;
  double result = 0;
  printf("temp %g\n", temp);
  result = strtod(string, &string_rem);

  if (string[0]== '+' || string[0] == '-') {
    result += temp;
    return result;
  }
  if (string[0]== '*'){
    string++;
    result = temp * strtod(string, &string_rem);
    return result;
  }
    if (string[0]== '/'){
      string++;
      result = temp / strtod(string, &string_rem);
      return result;
  }


  if (strnstr(string_rem, "memory^", 7)) {
    printf("memory found\n");
    printf("memory = %g", memory);
    result = (memory * memory);
    string_rem += 7;
    return result;
  }
  if (strnstr(string_rem, "memory#", 7)) {
    printf("memory found\n");
    printf("memory = %g", memory);
    result = sqrt(memory);
    string_rem += 7;
    return result;
  }
  if (strnstr(string_rem, "memory", 6)) {
    printf("memory found\n");
    printf("memory = %g", memory);
    result = memory;
    string_rem += 6;
    //return result;
  }



  printf("%gRESULT FIRST\n", result);
  printf("%sSTRING_REM FIRST\n", string_rem);
  while ((*string_rem) && !exit_calc) {


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


          temp = sqrt(temp);
          string_rem++;
        }
        if (strnstr(string_rem, "memory^", 7)) {
          printf("memory found\n");
          printf("memory = %g", memory);
          result = result + (memory * memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory#", 7)) {
          printf("memory found\n");
          printf("memory = %g", memory);
          result = result + sqrt(memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory", 6)) {
          printf("memory found\n");
          printf("memory = %g", memory);
          result = result + memory;
          string_rem += 6;
          break;
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

            temp = sqrt(temp);
          string_rem++;
        }
        if (strnstr(string_rem, "memory^", 7)) {
          printf("memory found\n");
          printf("memory = %g", memory);
          result = result - (memory * memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory#", 7)) {
          printf("memory found\n");
          printf("memory = %g", memory);
          result = result - sqrt(memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory", 6)) {
          printf("memory found\n");
          printf("memory = %g", memory);
          result = result - memory;
          string_rem += 6;
          break;
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


          temp = strtod(string, &string_rem);
        if (string_rem[0] == '^') {

          temp = temp * temp;
          string_rem++;
        }
        if (string_rem[0] == '#') {

            temp = sqrt(temp);
          string_rem++;
        }
        if (strnstr(string_rem, "memory^", 7)) {
          printf("memory found\n");
          printf("memory = %g", memory);
          result = result * (memory * memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory#", 7)) {
          printf("memory found\n");
          printf("memory = %g", memory);
          result = result * sqrt(memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory", 6)) {
          printf("memory found\n");
          printf("memory = %g", memory);
          result = result * memory;
          string_rem += 6;
          break;
        }
        result = result * temp;
        printf("TIMES\n");
      //  return result;
        break;
        case '/':
        string_rem++;
        string = string_rem;


          temp = strtod(string, &string_rem);
        if (string_rem[0] == '^') {

          temp = temp * temp;
          string_rem++;
        }
        if (string_rem[0] == '#') {

            temp = sqrt(temp);
          string_rem++;
        }
        if (strnstr(string_rem, "memory^", 7)) {
          printf("memory found\n");
          printf("memory = %g", memory);
          result = result / (memory * memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory#", 7)) {
          printf("memory found\n");
          printf("memory = %g", memory);
          result = result / sqrt(memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory", 6)) {
          printf("memory found\n");
          printf("memory = %g", memory);
          result = result / memory;
          string_rem += 6;
          break;
        }

        result = result / temp;
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
        printf("error\n");
        exit_calc =1;
        break;
    }



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
void prompt(void) {
  printf("Calc:\\> ");
  calc_string = get_string(input);


}

void reset(void){
  answer = 0;
  memory = 0;
  puts("Type \"HELP\" or enter a mathematical expression");
}

int eval_input(char *string){
  char first_letter = string[0];
  int comp;

  comp = strcmp(string, "exit");
  if (comp == 0){
    exit_calc = 1;
    printf("Thankyou for using Calculator.\nGoodbye!\n");
    return 0;
  }
  comp = strcmp(string, "help");
  if (comp == 0){
    print_help();
    return 0;
  }
  comp = strcmp(string, "store");
  if (comp == 0){
    memory = answer;
    return 0;
  }

  comp = strcmp(string, "reset");
  if (comp == 0){
    reset();
    return 0;
  }

  answer = to_num2(calc_string);
  // switch (first_letter){
  //   case '+':
  //     printf("Starts with plus\n");
  //     break;
  //     default:
  //     break;
  // }
  print_answer();
  return 0;
}
void print_help(void){
  printf("EXIT\t\tExits this program.\n");
  printf("HELP\t\tDisplays information about this program.\n");
  printf("MEMORY\t\tAs part of a mathematical expression the term MEMORY\n");
  printf("\t\tis substituted by the value stored in memory. Otherwise,\n");
  printf("\t\tthe value stored in memory is displayed on-screen.\n");
  printf("RESET\t\tErases stored memory and returns calculator to its\n");
  printf("\t\tinitial 'start-up' mode.\n");
  printf("STORE\t\tSaves current answer to memory.\n\n");
  printf("OPERATOR\t\tDESCRIPTION\t\tSYNTAX\n");
  printf("+\t\taddition\t\t[a + b:+a]\n");
  printf("-\t\taddition\t\t[a - b:-a]\n");
  printf("*\t\taddition\t\t[a * b:*a]\n");
  printf("\\\t\taddition\t\t[a / b:/a]\n");
  printf("^\t\taddition\t\ta^\n");
  printf("#\t\taddition\t\ta#\n\n");
  printf("Example:\t a^ +b#/ MEMORY (spacing optional)");


}
void print_answer(){
  if (answer == trunc(answer)){
    printf("%s%g\n", "Answer:\\> ", answer);
  } else

  printf("%s%f\n", "Answer:\\> ", answer);
}
