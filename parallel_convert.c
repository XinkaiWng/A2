/* Information
CSci 4061 Spring 2015 Assignment 2 
Name1=FullName
Name2=FullName
StudentID1=ID for First name 
StudentID2=ID for Second name 
Commentary=description of the program, problems encountered while coding, etc.
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  pid_t child_pid;
 
  int convert_count;
  char* output=argv[2];
  char* input=argv[3];
  //check to see proper number of arguments
  if(argc != 4)
    {
      printf("usage: parallel_convert convert_count output_dir input_dir\n");
      exit(-1);
    }
  //
  if (sscanf (argv[1], "%i", &convert_count)!=1)
    {
      printf("error - not an integer");
    }
 //printf("convert_count: %i\n input: %s\n", convert_count, input);
 
  if (mkdir(output, 0777) == -1)
    {
      perror("Error");
    }
 return 0;
}
