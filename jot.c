#include <stdio.h>
#include <stdlib.h>

#include "date_format.h"
#include "options.h"

int main(int argc, char **argv) {
  char buf[32] = {0};
  char cmd[4096] = {0};

  options_t args = parse_args(argc, argv);
  args.date_format(args.as_of, buf, 32);
  snprintf(cmd, 4096, "%s \"%s%s%s.%s\"", args.editor, args.root, args.prefix,
           buf, args.suffix);

  return system(cmd);
}
