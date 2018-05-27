#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char * get_string(char *string);
double calculate_exp(char *string);
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
  reset();
  while (!exit_calc){
    prompt();
    removeSpaces(calc_string);
    eval_input(calc_string);
  } // end while
} // end main

char * get_string(char *string) {
  char c = getchar();
  size_t i=0;
  string[i] = c;
  while (c!='\n'){
    string[i] = c;
    i++;
    c=getchar();
  } // end while
  string[i] = '\0';
  return string;
} // end get_string

double calculate_exp(char *string) {
  char * string_rem;
  double temp = answer;
  double result = 0;
  int error = 0;
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
    result = (memory * memory);
    string_rem += 7;
    return result;
  }
  if (strnstr(string_rem, "memory#", 7)) {
    result = sqrt(memory);
    string_rem += 7;
    return result;
  }
    if (strnstr(string_rem, "memory", 6)) {
    result = memory;
    string_rem += 6;
  }

  while ((*string_rem) && !error) {
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
          result = result + (memory * memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory#", 7)) {
          result = result + sqrt(memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory", 6)) {
          result = result + memory;
          string_rem += 6;
          break;
        }
        result = result + temp;
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
          result = result - (memory * memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory#", 7)) {
          result = result - sqrt(memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory", 6)) {
          result = result - memory;
          string_rem += 6;
          break;
        }
        result = result - temp;
        break;

      case '*':
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
        if (strnstr(string_rem, "memory^", 7) || strnstr(string_rem, "MEMORY^", 7)) {
          result = result * (memory * memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory#", 7) || strnstr(string_rem, "MEMORY#", 7)) {
          result = result * sqrt(memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory", 6) || strnstr(string_rem, "MEMORY", 6)) {
          result = result * memory;
          string_rem += 6;
          break;
        }
        result = result * temp;
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
        if (strnstr(string_rem, "memory^", 7) || strnstr(string_rem, "MEMORY^", 7)) {
          result = result / (memory * memory);
          string_rem += 7;
          break;
          }
        if (strnstr(string_rem, "memory#", 7) || strnstr(string_rem, "MEMORY#", 7)) {
          result = result / sqrt(memory);
          string_rem += 7;
          break;
        }
        if (strnstr(string_rem, "memory", 6) || strnstr(string_rem, "MEMORY", 6)) {
          result = result / memory;
          string_rem += 6;
          break;
        }
        result = result / temp;
        break;

      case '^':
        string_rem++;
        string = string_rem;
        result = result * result;
        break;

      case '#':
        string_rem++;
        string = string_rem;
        result = sqrt(result);
        break;

      default:
        printf("Error with input. Please try again.\n");
        error = 1;
        break;

      } // end switch
  } // end while
  return result;
} //end calculate_exp

void removeSpaces(char *str)
{
  // To keep track of non-space character count
  int count = 0;
  // Traverse the given string. If current character
  // is not space, then place it at index 'count++'
  for (int i = 0; str[i]; i++)
  if (str[i] != ' ')
  str[count++] = str[i];  // here count is
                          // incremented
  str[count] = '\0';
}

void prompt(void) {
  printf("Calc:\\> ");
  calc_string = get_string(input);
} // end prompt

void reset(void){
  answer = 0;
  memory = 0;
  printf("\033[H\033[J");
  puts("Type \"HELP\" or enter a mathematical expression");
} // end reset

int eval_input(char *string){
  char first_letter = string[0];
  int comp;

  comp = strcasecmp(string, "exit");
  if (comp == 0){
    exit_calc = 1;
    printf("Thankyou for using Calculator.\nGoodbye!\n");
    return 0;
  }

  comp = strcasecmp(string, "help");
  if (comp == 0){
    print_help();
    return 0;
  }

  comp = strcasecmp(string, "store");
  if (comp == 0){
    memory = answer;
    printf("ANSWER STORED in MEMORY\n");
    return 0;
  }

  comp = strcasecmp(string, "reset");
    if (comp == 0){
    reset();
    return 0;
  }

  answer = calculate_exp(calc_string);
  print_answer();
  return 0;
} // end eval_input

void print_help(void){
  printf("\nEXIT\t\tExits this program.\n");
  printf("HELP\t\tDisplays information about this program.\n");
  printf("MEMORY\t\tAs part of a mathematical expression the term MEMORY\n");
  printf("\t\tis substituted by the value stored in memory. Otherwise,\n");
  printf("\t\tthe value stored in memory is displayed on-screen.\n");
  printf("RESET\t\tErases stored memory and returns calculator to its\n");
  printf("\t\tinitial 'start-up' mode.\n");
  printf("STORE\t\tSaves current answer to memory.\n\n");
  printf("OPERATOR\tDESCRIPTION\tSYNTAX\n");
  printf("+\t\taddition\t[a + b:+a]\n");
  printf("-\t\tsubtraction\t[a - b:-a]\n");
  printf("*\t\tmultiplication\t[a * b:*a]\n");
  printf("/\t\tdivision\t[a / b:/a]\n");
  printf("^\t\tsqr(x)\t\ta^\n");
  printf("#\t\tsqrt(x)\t\ta#\n\n");
  printf("Example:\ta^ +b#/ MEMORY (spacing optional)\n");
} // end print_help

void print_answer(){
  if (answer == trunc(answer)){
    printf("%s%g\n", "Answer:\\> ", answer);
  } else
    printf("%s%f\n", "Answer:\\> ", answer);
} // end print_answer
