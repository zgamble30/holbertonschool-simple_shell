#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


char** shell_split_line(char *line) 
{
    int length = 0;
    int capacity = 16;
    char **tokens = malloc(capacity * sizeof(char*));

    char *delimiters = " \t\r\n";
    char *token = strtok(line, delimiters);

    while (token != NULL) 
      {
        tokens[length] = token;
        length++;

            if (length >= capacity) 
       	       {

	            capacity = (int) (capacity * 1.5);
        	    tokens = realloc(tokens, capacity * sizeof(char*));
              
               } 

           token = strtok(NULL, delimiters);
       }

    tokens[length] = NULL;
    return tokens;
}




char* shell_read_line() 
{
    char *line = NULL;
    size_t buflen = 0;
    getline(&line, &buflen, stdin);
    return line;
}


void shell_exec(char **args) 
{     


    pid_t child_pid = fork();

    if (child_pid == 0) 
      {
        execve(args[0], args, NULL);
        perror("Shell");
        exit(1);
      }
 
    else if (child_pid > 0)
     	  {
       	     int status;
	     wait(&status);
          }
 
     else
        {

        perror("Shell");

        }
}






int main() 
{
    while (true) 
    {
        printf("$ ");
        char *line = shell_read_line();
        char **tokens = shell_split_line(line);

        if (tokens[0] != NULL) 
	{
            shell_exec(tokens);
        }

        free(tokens);
        free(line);
    }
}
