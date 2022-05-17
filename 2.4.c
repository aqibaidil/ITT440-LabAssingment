#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void childTask(){
    printf("Enter your name: ");  
    char name[10];
    fgets(name, 10, stdin);
    printf("Hello %s \n", name);
}
void parentTask(){
    printf("\nWaiting for child process..\n "); 
    printf("Job is done\n\n");
}
int main(void)  
{
    for (int  i = 1; i<5; i++){
        pid_t pid = fork();
        
        if (pid == 0) {
            childTask();
            exit(0);
        }
    
    
        else if (pid > 0) {
            wait(NULL);
            parentTask();

        }
        
        else{
            printf("Unable to process.");
            }
    }
        return EXIT_SUCCESS;
}
