#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

int main(int argc, char *argv[]){
	char shellcode[] = ("\xCC");

	void *shellcode_location = mmap(0,sizeof(shellcode),PROT_EXEC | PROT_WRITE | PROT_READ, MAP_ANON | MAP_PRIVATE, -1,0);
 
	printf("Your shellcode is mapped at: %p\n",shellcode_location);

	memcpy(shellcode_location,shellcode,sizeof(shellcode));

	goto *shellcode_location;

	return 0;
};
