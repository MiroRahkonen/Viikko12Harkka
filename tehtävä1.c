#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void deletefile(){
    unlink("tempfile.txt");
    exit(0);
}


int main(void){
    FILE *tempfile;
    int i;
    tempfile = fopen("tempfile.txt","w");
    
    atexit(deletefile);
    signal(SIGINT,deletefile);

    if(tempfile == NULL){
        printf("Unable to open temporary file\n");
        exit(1);
    }
    
    for(i=1; i<11; i++){
        fprintf(tempfile,"%d. line\n",i);
        //printf("Line written\n");
        sleep(1);

    }
    
    return 0;
}