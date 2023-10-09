#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("Welcome to kokbtw!\n");

  if (argc < 2) {
    printf("Wrong usage!!\n");
    return -1;
  }

  FILE *in = fopen(argv[1], "r");
  FILE *out = fopen(argv[2], "w");

  if (in == NULL || out == NULL) {
    printf("Could not open the files.\n");
    return -1;
  }

  char buff[256];
  char write_buff[256];
  int open_bold = 0;
  while (fgets(buff, 256, in)) {
    if (buff[0] == '/') {
      buff[0] = ' ';
      strcpy(write_buff, buff);
    } else {
      strcat(write_buff, " => ");
      strcat(write_buff, buff);
    }

    fprintf(stdout, "%s", write_buff);
    fprintf(out, "%s", write_buff);
    for (size_t i = 0; i < 256; i++) write_buff[i] = '\0'; 
  }

  printf("Written to %s\n", argv[2]);
  
  return 0;
}
