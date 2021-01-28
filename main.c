#include <stdio.h>
#include <math.h>
#define Pi 3.14159265358


double rad_conver(double r, double de){
    r = (de * Pi / 180);
    return r;
}

int check_diff(double dif) {
    if(dif >= 0.000001){
        return 1;
    } else {
        return 0;
    }
}
double sine(double total1, double a, double transf, double dif, double k, int i, int *counter) {
    double total2 = a;
    total1 = a;
    double total0 = 0;
    dif = 1.0;
    *counter = 2;
    do {
        k = (pow(a, 2)/((2*i-2)*(2*i-1))) * pow(-1,i+1);
        total2 = total1  + k*fabs(total1 - total0);
        dif = fabs(total2- total1);
        total0 = total1;
        total1 = total2;
        i++;
        *counter = *counter + 1;
    } while(check_diff(dif));
    return total2;
}

double cosine(double total1, double a, double transf, double dif, double k, int i, int *counter) {
    
    double total2 = 1.0;
    total1 = 1.0;
    double total0 = 0;
    dif =1.0;
    *counter = 2;

    do {
        k = (pow(a, 2)/(((2*i)-2)*((2*i)-3))) * pow(-1,i+1);
        total2 = total1 + k*fabs(total1 - total0);
        dif = fabs(total2- total1);
        total0 = total1;
        total1 = total2;
        i++;
        *counter = *counter + 1;
    } while(check_diff(dif));
    return total2;
}


int main() {
    double degrees = 0.0, rad = 0.0, k = 0.0, dif = 1.0, transf = 0.0, total = 0, sineRes, cosineRes;
    int i;
    int counter, counter2;
    for(degrees = 30.0; degrees <= 180.0; degrees+=10.0){
        rad = rad_conver(rad, degrees);
        i = 2;
        sineRes = sine(total, rad, transf, dif, k, i, &counter);
        printf("sine = %lf\n", sineRes);
        printf("sine counter == %d\n\n", counter);
        cosineRes = cosine(total, rad, transf, dif, k, i, &counter2);
        printf("cosine = %lf\n", cosineRes);
        printf("cosine counter == %d\n\n", counter2);
        if(counter > counter2) {
            printf("sine counter is larger\n");

        } else if (counter < counter2) {
            printf("cosine counter is larger\n");

        } else {
            printf("equal\n");

        }
        printf("\n");
    }
       
    return 0;
}
