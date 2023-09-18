#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ChangeExtensions [old_extension] [new_extension]\n");
    return 1;
  }

  char *old_extension = argv[1];
  char *new_extension = argv[2];

  char command[FILENAME_MAX];
  snprintf(command, FILENAME_MAX, "for file in *.%s; do mv -- \"$file\" \"$(basename \"$file\" .%s).%s\"; done", old_extension, old_extension, new_extension);

  int status = system(command);
  if (status == -1) {
    perror("Error renaming files");
    return 1;
  }

  return 0;
}

