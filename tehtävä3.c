#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *first(void * par)
{
    sleep(1);
    fputs("The quick brown fox jumped ", stdout);
    return NULL;
}

void *second(void *par){
    fputs("over the lazy dog\n",stdout);
    return NULL;
}

int main(void)
{
    pthread_t fid, sid;

    if (pthread_create(&fid, NULL, first, NULL) != 0) {
        perror("pthread_create");
        exit(1);
    }
    pthread_join(fid,NULL);

    if (pthread_create(&sid,NULL,second,NULL) != 0){
        perror("pthread_create");
        exit(1);
    }
    pthread_join(sid,NULL);
    return 0;
}