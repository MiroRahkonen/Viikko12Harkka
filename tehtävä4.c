#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>

/*Source for calculating value of pi*/
/*https://www.codesansar.com/c-programming-examples/calculate-value-pi-using-leibniz-formula.htm*/

/* declare as volatile to make sure the compiler does not optimize the variables to fixed values */
volatile double result=0.0;
volatile long long j=1;

/* approximation of pi/4 by Leibniz' series */
void * compute(void * par) {
    int i = 0;
    double term;
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
    while (j>=0) {
        term = pow(-1, i) / (2*i+1);  /*source for calculating pi above*/  
        result += term;
        i++;
        usleep(1000);    
    }
    return NULL;
}

int main(int argc, char ** argv)
{
    pthread_t cid;
    int sec,c=0;
    
    if(argc<2){
        printf("usage: ./tehtävä1 [1,2...]\n");
        exit(0);
    }
    sec=atoi(argv[1]);
    pthread_create(&cid,NULL,compute,NULL);
    printf("Computing values for %d seconds\n",sec);
    while (c<sec--) {
        printf("Current estimate: %.10f\n",result*4);
        sleep(1);
    }
    pthread_cancel(cid);
    pthread_join(cid,NULL);
    printf("The final approximate of pi is: %.10f\n",result*4);
    return 0;
}