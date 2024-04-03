#include <stdio.h>
#include <math.h>

struct tipoPonto{
    int x;
    int y;
};

double distancia(struct tipoPonto a, struct tipoPonto b){
    double d = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.x), 2));
    return d;
}