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


void storer(int to,int from){
    strcpy(memory[reg[to]],int_Tochar(reg[from]));
	reg[pc]=reg[pc]+1;
}
	

void add(int reg1,int reg2){
    reg[acc]=reg[reg1]+reg[reg2];
	reg[pc]=reg[pc]+1;
}
	

void sub(int reg1,int reg2){
    reg[acc]=reg[reg1]-reg[reg2];
	reg[pc]=reg[pc]+1;
}
	

void mod(int reg1,int reg2){
    reg[acc]=reg[reg1] % reg[reg2];
	reg[pc]=reg[pc]+1;
}
	

void call(int address){
    reg[sp]=reg[sp]+1;
	strcpy(memory[reg[sp]],int_Tochar(reg[pc]+1));
	reg[pc]=address;
}
	

void ret(){
    reg[pc]=char_toint(memory[reg[sp]]);
	reg[sp]=reg[sp]-1;
}
	

void out(int reg1){
    //printf("%s = %d\n",reg_names[reg1],reg[reg1]);
    printf("%d\n",reg[reg1]);
	reg[pc]=reg[pc]+1;
}