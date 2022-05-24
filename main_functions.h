#include"assembly_functions.h"

void initialize_memory(char** memory,int max_len){

    for(int i = 0;i<SIZE;i++){
        *(memory+i) = (char*)malloc(max_len*sizeof(char));
        *(*(memory+i)+0) = '0';
    }

}

void initialize_reg(){
    for(int i=0;i<REG_SIZE;i++){
        reg[i] = 0;
    }
}
