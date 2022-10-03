#include "lacc.h"

static struct option longopts[] = {
    {"output", required_argument, NULL, 'o'},
    {"help", no_argument, NULL, 'h'},
    {0, 0, 0, 0},
};

int main(int argc, char **argv) {
  int opt;
  char *output_file_name;

  output_file_name = "a.out";
  while ((opt = getopt_long(argc, argv, "o:h", longopts, NULL)) != -1) {
    switch (opt) {
      case 'o':
        output_file_name = optarg;
        break;
      case 'h':
        fprintf(stdout, "Usage: lacc [--output=o <file>] sources...\n");
        exit(0);
        break;
      default:
        fprintf(stdout, "Usage: lacc [--output=o <file>] sources...\n");
        exit(1);
        break;
    }
  }

  if (optind != argc - 1 && optind != 2) {
    fprintf(stdout, "Usage: lacc [--output=o <file>] sources...\n");
    exit(1);
  }

  lacc_main(output_file_name, argv[optind]);

  return (0);
}

void lacc_main(char *output, char *input) {}
