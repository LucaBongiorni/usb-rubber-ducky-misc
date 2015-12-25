/*
  Name: CTD (CodeToDucky)
  Version: 0.1
  Autor: @codexlynx
  Date: 20/12/15
  License: Creative Commons Share-Alike 3.0
  
  Description: 
               
     You can transform a scripting code (Batch, Bash, PowerShell...) in Rubber Ducky
     Payload scripting language.
     
*/

#include <stdio.h>

int main(int argc, char *argv[]){
    
    char line[BUFSIZ];
    FILE *code;
    FILE *result;
    
    printf("CTD (CodeToDucky) v0.1 - Transform code in USB Rubber Ducky Payload\n\n");
    
    if( argc > 2 ){                       
       code = fopen(argv[1], "r");
       
       if( code == NULL ){
           printf("   [-]Error while opening the file.\n");
       }else{
           printf("   [*]Reading: %s...\n", argv[1]);
           result = fopen(argv[2], "w+");
           
           if( result == NULL ){
               printf("   [-]Error while writing the file.\n");    
           }else{
               printf("   [*]Writing: %s...\n", argv[2]);
               
               while(fgets(line, 80, code) != NULL){
                    fprintf(result, "STRING %s", line);
                    fprintf(result, "ENTER\n");
               }
               
           }
           fclose(result);
           
       }
       fclose(code);
      
    }else{
       printf("   Usage: %s <input code file> <output>\n", argv[0]);
    }

    printf("\nCreate by: @codexlynx\n");
    return 0;  
}
