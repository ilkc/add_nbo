#include<stdio.h>
#include<stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

uint32_t op_read(char* filename){
	uint32_t re_byte;
	FILE * fp = fopen(filename, "rb");
	
	if(fp == NULL){
		fputs("File error", stderr);
    		exit(1);
	}
	
	fread(&re_byte, 1, 4, fp);
	
	return ntohl(re_byte);
}


int main(int argc, char* argv[]){
	uint32_t first = op_read(argv[1]);
	uint32_t second = op_read(argv[2]);
	printf("%d(%x) + %d(%x) = %d(%x)", first, first, second, second, first+second, first+second);
	return 0;
}

