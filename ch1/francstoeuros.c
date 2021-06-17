#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double conversion(double francs)
{
    double euros = 0;
    
    euros = francs/6.55957;
    return euros;
}    

int main(int argc, char *argv[])
{    
    printf("10 francs = %f euros\n", conversion(10));
    printf("50 francs = %f euros\n", conversion(50));
    printf("100 francs = %f euros\n", conversion(100));
    printf("200 francs = %f euros\n", conversion(200));
    
    return 0;
}