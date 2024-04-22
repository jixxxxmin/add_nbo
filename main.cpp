#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>


uint32_t load_file(char *path){

	FILE *file;
	uint32_t data;
	file = fopen(path, "rb");
	uint32_t data_size = fread(&data, 1, sizeof(data), file);
	fclose(file);

	data = ntohl(data);

	return data;
}


void add_num(uint32_t data1, uint32_t data2){
	
	uint32_t data3 = data1 + data2;
	printf("%d(%x) + %d(%x) = %d(%x)", data1, data1, data2, data2, data3, data3);
}


int main() {
	
	uint32_t data1, data2;	
	data1 = load_file("thousand.bin");
	data2 = load_file("five-hundred.bin");

	add_num(data1, data2);

	return 0;
}
