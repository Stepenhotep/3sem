#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	pid_t pid;
   	int status;
	while(1==1)
	{  	
		switch(pid = fork()) {
	   		case 0: 
				printf (">");
				char s[100];
				gets(s);
				//printf ("\n %d \n", strcmp(s, "qwerty"));
				if (s[0] == 'q' && s[1] == 0) exit(-2);				
				int len = strlen(s);
				int n = 0;
				int i, j;
				for (i = 0; i < len; i++){
					if (s[i] == ' '){
						n++;
						s[i] = 0;
					}
				}
				char **argv = (char **)malloc((n + 2)*sizeof(char*));
				argv[n + 1] = NULL;
				n = 0;
				j = 0;
				for (i = 0; i < len; i++){	
					if(i == 0 || s[i-1] == 0){
						argv[n] = s + i;
						n++;		
					}
			
				}
				//puts(argv[2]);
				execvp(argv[0], argv);
				printf ("exec error");	
	   		case -1:
				exit(-1);
			default:
			
				wait(&status);
				if (WEXITSTATUS(status) == 254) exit(-1);
				printf("\nexit status %d \n", WEXITSTATUS(status)); // this is the code the parent runs
	   	}
	}
	return 0;
}
