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
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

#define MAX_DIR_PATH 2048

char cwd[MAX_DIR_PATH + 1];

/*********************************************************************************
 *
 * Main
 *
 *
 ********************************************************************************/

int main(int argc, char *argv[])
{
  //pid_t child_pid;
 
  int convert_count;
  char* output=argv[2];
  char* input=argv[3];
  char filelist[100][NAME_MAX+1];
  int iouou=0;
  int size;
  int i=0, p=0, b=0, g=0;
  char pngList[100][65];
  char bmpList[100][65];
  char gifList[100][65];

//******************************************************************************************
  //Find files of specified pattern
  DIR *directHandler;  //This pointer handles the directory open call
  struct dirent *drecord; //This is a structure pointer named drecord to store the file information that is read from the directory

  directHandler = opendir(input);
  if(directHandler == NULL)
    {
      puts("Error opening directroy");
      return(1);
    }
  while( (drecord = readdir(directHandler)) != NULL)
    {
      if (strcmp (drecord->d_name, ".") == 0)
	continue;
      
      if (strcmp (drecord->d_name, "..") == 0)
	continue;
      if (drecord->d_name && strstr (drecord->d_name, ".png"))
	{
         //printf("drecord->d_name: %s\n", drecord->d_name);
	 strcpy(filelist[iouou], drecord->d_name);
         printf("filelist[%d]: %s\n",iouou,filelist[iouou]);
     	}
      if (drecord->d_name && strstr (drecord->d_name, ".bmp"))
	{
         //printf("drecord->d_name: %s\n", drecord->d_name);
	 strcpy(filelist[iouou], drecord->d_name);
         printf("filelist[%d]: %s\n",iouou,filelist[iouou]);
     	}
      if (drecord->d_name && strstr (drecord->d_name, ".gif"))
	{
         //printf("drecord->d_name: %s\n", drecord->d_name);
	 strcpy(filelist[iouou], drecord->d_name);
         printf("filelist[%d]: %s\n",iouou,filelist[iouou]);
     	}
      
      //printf("There is %d files being converted\n", i);
      iouou++;
    }
  closedir(directHandler);
//******************************************************************************************************

//Sorting image files into separate arrays
for (i; i < 100 && (strlen(filelist[i]) != 0); i++)
{
	//Move png files into png array
	if(strstr(filelist[i], ".png") != NULL)
	{
		strncpy(pngList[p], filelist[i], (strlen(filelist[i])-4));
		//printf("pngList[%d]: %s\n", p, pngList[p]);
		p++;

	}

	//Move bmp files into bmp array
	if(strstr(filelist[i], ".bmp") != NULL)
	{
		strncpy(bmpList[b], filelist[i], (strlen(filelist[i])-4));
		//printf("bmpList[%d]: %s\n", b, bmpList[b]);
		b++;

	}

	//Move gif files into gif array
	if(strstr(filelist[i], ".gif") != NULL)
	{
		strncpy(gifList[g], filelist[i], (strlen(filelist[i])-4));
		printf("gifList[%d]: %s\n", g, gifList[g]);
		g++;

	}
}


//printf("pnglist[0]: %d\n", sizeof(filelist));
//printf("filelist[56]: %d\n", strlen(filelist[56]));
//printf("filelist[2]: %s\n", filelist[2]);
 
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
