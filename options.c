#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

#include "date_format.h"
#include "options.h"

#ifndef VERSION
#define VERSION "devel"
#endif

void usage(int argc, char **argv) {
  fprintf(
      stderr,
      "Usage:\n"
      "\t%s [-e <editor>] [-p <prefix>] [-r <root>] [-s <suffix>] [-d|t|i]\n"
      "\n"
      "\t\t-d\tuse current date\n"
      "\t\t-t\tuse current time\n"
      "\t\t-i\t(default) use current iso-8601 time\n"
      "",
      argv[0]);
}

options_t parse_args(int argc, char **argv) {
  // initialize
  options_t opts;
  opts.editor = getenv("EDITOR");
  opts.prefix = getenv("JOT_PREFIX");
  opts.suffix = getenv("JOT_SUFFIX");
  opts.root = getenv("JOT_ROOT");
  opts.as_of = time(0);
  opts.date_format = format_time_iso8601;

  // parse cmdline

  char opt = 0;
  char **next = 0;
  for (int i = 0; i < argc; i++) {
    if (0 == strncmp(argv[i], "-", 1)) {
      if (next != 0) {
        fprintf(stderr, "error: expecting value for option -%c\n", opt);
        usage(argc, argv);
        exit(-1);
      }

      int j = 1;
      while (argv[i][j++] != 0) {
        char tok = argv[i][j - 1];
        switch (tok) {
        case 'h':
          usage(argc, argv);
          exit(0);
        case 'e':
          opt = tok;
          next = &opts.editor;
          break;
        case 'p':
          opt = tok;
          next = &opts.prefix;
          break;
        case 'r':
          opt = tok;
          next = &opts.root;
          break;
        case 's':
          opt = tok;
          next = &opts.suffix;
          break;
        case 'd':
          opts.date_format = format_date;
          break;
        case 't':
          opts.date_format = format_time;
          break;
        case 'i':
          opts.date_format = format_time_iso8601;
          break;
        case 'v':
          fprintf(stdout, "version: %s\n", VERSION);
          exit(0);
        default:
          fprintf(stderr, "OPTION -%c unknown\n", tok);
          break;
        }
      }
    } else {
      if (next != 0) {
        *next = argv[i];
        next = 0;
        opt = 0;
      }
      // TODO: consider inserting any extra strings into the file
    }
  }

  if (next != 0) {
    fprintf(stderr, "error: expecting value for option -%c\n", opt);
    usage(argc, argv);
    exit(-1);
  }

  // failsafe cleanup
  if (opts.suffix != NULL && opts.suffix[0] == '.') {
    opts.suffix = opts.suffix + 1;
  }

  if (opts.editor == NULL || opts.editor[0] == 0) {
    opts.editor = "vi";
  }

  if (opts.prefix == NULL) {
    opts.prefix = "";
  }

  if (opts.suffix == NULL) {
    opts.suffix = "md";
  }

  if (opts.root == NULL) {
    opts.root = "";
  }

  return opts;
}
