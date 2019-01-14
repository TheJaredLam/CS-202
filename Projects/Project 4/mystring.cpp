#include <iomanip>
#include "mystring.h"

size_t myStringLength(const char * str)
{
  int size = 0;
  for(; *str != '\0'; str++) {
    size++;
  }
  return size;
}

char * myStringCat(char * destination, const char * source)
{
  unsigned int dest_len = myStringLength(destination);
  unsigned int src_len = myStringLength(source);
  unsigned int j;
  for(j = 0; j < src_len; j++) {
    *(destination + dest_len + j) = *(source + j);
  }
  *(destination + dest_len + src_len) = '\0';
  return destination;
}

int myStringCompare(const char *str1, const char *str2)
{
  while(* str1 != '\0' && * str2 != '\0') {
    if(* str1 < * str2) return -1;
    if(* str2 < * str1) return 1;
    str1++; str2++;
  }
  if(str1 == NULL && str2 != NULL) return -1;
  if(str2 == NULL && str1 != NULL) return 1;
  return 0;
}

char * myStringCopy(char * destination, const char * source) {
  for(; *source != '\0'; source++, destination++) {
    * destination = *source;
  }
  * destination = '\0';
  return destination;
}
