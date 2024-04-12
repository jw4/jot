#pragma once

#include <stdbool.h>
#include <sys/types.h>

void usage(int argc, char **argv);

typedef int (*date_handler)(time_t, char *, size_t);

typedef struct {
  char *editor;
  char *prefix;
  char *suffix;
  char *root;
  time_t as_of;
  date_handler date_format;
  bool dry_run;
} options_t;

options_t parse_args(int argc, char **argv);
