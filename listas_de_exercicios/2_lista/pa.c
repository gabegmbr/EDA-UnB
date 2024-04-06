#include <stdio.h>

int pa_recursiva(int *v, int primeiro, int ultimo){
    if(++primeiro > ultimo){
        if((v[primeiro+1] + v[ultimo-1]) == (v[primeiro]+v[ultimo])){
            return 1;
        }
        else{
            return 0;
        }
    }
    if((v[primeiro+1] + v[ultimo-1]) == (v[primeiro]+v[ultimo])){
        pa_recursiva(v, ++primeiro, --ultimo);
    }
    else{
        return 0;
    }
}
