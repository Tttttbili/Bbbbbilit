#include <stdio.h>
#include <string.h>
#include <malloc.h>

char* substring(char*, int, int);

int main(){
char string[100], *pointer;
int position = 1, length = 1, temp, string_length;

printf("Enter a string\n");
scanf("%s",string);

string_length = strlen(string);

printf("Suffix Tree of \"%s\" are\n", string);
int i;
for(i=string_length;i>=0;i--){
pointer = substring(string ,string_length-i, string_length);
printf("%s\n", pointer);
free(pointer);
}
return 0;
}
char *substring(char *string, int position, int length) {
char *pointer;
int c;
pointer = malloc(length+1);
if (pointer == NULL){
printf("Unable to allocate memory.\n");
}
for (c = 0 ; c < length ; c++){
*(pointer+c) = *(string+position-1);
string++;   
}
*(pointer+c) = '\0';
return pointer;
}