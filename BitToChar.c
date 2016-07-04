/* Hamdi Hmimy
   Professor Keathly
   2/25/2015
   My program will change characters to bit and will change bit
   to the proper character.
*/


#include <stdio.h>
#include <stdlib.h>

void decrypt(char *,char *);
void encrypt(char *,char *);

int main(int argc,char *argv[])
{
   if( argc != 4)                    /* if statement for error checking*/
    {
      printf("Error need 4 arguments\n",argv[0]);
    }
   else if(strcmp(argv[1],"encrypt") == 0)
   {   
    encrypt(argv[2],argv[3]);		/* encrypting function using 2 parameters*/
   }
 

else if(strcmp(argv[1],"decrypt")==0)
  {
  decrypt(argv[2],argv[3]);		/*decrypting function using 2 parameters*/
  }
  
}


void decrypt(char *input, char *output)

{
 int x;
 FILE *file1 = fopen(output,"w+");		/* opens files for reading and writing*/
 FILE *file= fopen(input,"r");
 while(!feof(file))
  {
      fscanf(file,"%d",&x);				/*scans the numbers to switch to bit compenent of characters to write to file*/
      char t = ~x;
      printf("%c",t);
      fprintf(file1,"%c",t);
  }
  fclose(file);

}

void encrypt(char *input,char *output)
{
  char x;
   FILE *file1 = fopen(output,"w+");		/* reads in each character to change in bit compenent of their integer and writes to file*/
   FILE *file= fopen(input,"r");
   while((x=fgetc(file)) != EOF)
     {
      int num = x;
      num = ~num;
      fprintf(file1,"%d",num);
     }
    fclose(file);
    fclose(file1);

}

