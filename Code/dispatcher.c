#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

/**
* @file C:\Users\Logan\Documents\CSC412\prog_04\Prog 03 Solution\Prog 03\dispatcher.c
* @author Logan
* @date 2 Nov 2019
* @copyright 2019 Logan
* @brief <prog_04>
*/

int main(int argc, char* argv[]) {

  /**
  * @brief <dispatcher for commands executed on images>
  * @param [main] <argc, argv> <commands to be executed on images>
  * @return <int>
  * @details
   function loops through arguments passed in argv
   checks if the first arg passed is either split rotate or crop
   if it finds one of those, it creates a char* array of the arguments which will be of
   a predetermined length due to the nature of the commands with the arguments that follow
   it will then execute the command through a child process that was already forked
   and the index will be moved so that it points to the next would-be command
  */


  //index starts at 1 because argv[0] = ./dispatch
  int index = 1;
  int childArray[argc];

  while (index < argc){

    if (!strcmp(argv[index],"./split")){
      childArray[index] = fork();
      //check if child
      if (childArray[index] == 0){
        char* arg[] = {argv[index], argv[index+1], argv[index+2], NULL};
        execvp(arg[0], arg);
      }
    index+=3;
    }

    else if (!strcmp(argv[index], "./crop")){
      childArray[index] = fork();
      //check if child
      if (childArray[index] == 0){
        char* arg[] = {argv[index], argv[index+1], argv[index+2],
          argv[index+3], argv[index+4], argv[index+5],
           argv[index+6], NULL};
        execvp(arg[0], arg);
      }
    index+=7;
    }

    else if (!strcmp(argv[index], "./rotate")){
      childArray[index] = fork();
      //check if child
      if (childArray[index] == 0){
        char* arg[] = {argv[index], argv[index+1], argv[index+2],
          argv[index+3], NULL};
        execvp(arg[0], arg);
      }
    index+=4;
    }
  }



  return 0;
}
