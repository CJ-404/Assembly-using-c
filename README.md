# Assembly-using-c
Create simple assembly virtual machine using c language.


## assembly functions description..

### mov(regTo , regFrom) - 
        move data from one register to another register.

### movv(regTo , data) - 
        move data directly to a register.

### load(regTo , memoryAddress) - 
        load data in a memory address directly to a register.

### loadr(regTo , regFrom) - 
        load data in memory address that stored in a register to another register.

### store(memoryAddress , regFrom) - 
        store data in a register to relavent memory address.

### storer(regTo , reg From) - 
        store data in a register to relavent memory address which stored in another register.

### add(reg1 , reg2) - 
        add 2 int values in 2 registers and store into the accumilator.

### sub(reg1 , reg2) - 
        store int value of { reg1 - reg2 } to accumilator.

### mod(reg1 , reg2) - 
        store value of { reg1 % reg2 } to accumilator.

### call(memoryAddress) - 
        store memory address of next instruction to be executed in stack after rising stack pointer & store inputed memory address into pc.

### ret() - 
        store memory address in stack into pc.

### out(reg) - 
        print data in given register.

### push(reg1) - 
        store data in given register in stack after rising stack pointer.

### pop(reg1) - 
        store last pushed data of stack into given register & decrease sp to next data in stack.

### jmp(memoryAddress) - 
        store given memory address into pc for execute that memory address next.( jump pc to given address).

### jnz(memoryAddress , reg) - 
        if data in given register NOT equal to 0(ZERO) ,  point pc to given memory address. else increase pc normaly by 1.

### holt() - 
        store 1 in register 'halt' to stop the program.

### print(word) - 
        print given word.
