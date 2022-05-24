#include"support_functions.h"


void mov(int to, int from){
    reg[to]=reg[from];
	reg[pc]=reg[pc]+1;
}
	

void movv(int to,int from){
    //printf("reg name = %s , address = %d\n",reg_names[to],from);
    reg[to]=from;
	reg[pc]=reg[pc]+1;
}

void load(int to,int from){
    reg[to]=char_toint(memory[from]);
	reg[pc]=reg[pc]+1;
}
	

void loadr(int to,int from){
    reg[to]=char_toint(memory[reg[from]]);
	reg[pc]=reg[pc]+1;
}
	

void store(int to,int from){
    strcpy(memory[to],int_Tochar(reg[from]));
	reg[pc]=reg[pc]+1;
}
