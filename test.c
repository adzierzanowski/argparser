#include <stdio.h>
#include "argparser.h"

int main(int argc, char *argv[])
{
  struct argparser_t *parser = argparser_new("test");

  struct option_init_t opt_c = {
    .short_name = "-c",
    .long_name = "--option-c",
    .help = "C Option",
    .required = true,
    .takes_arg = false 
  };

  struct option_init_t opt_d = {
    .short_name = "-d",
    .long_name = "--option-d",
    .help = "D option",
    .required = true,
    .takes_arg = true
  };

  argparser_add(parser, "-a", "--option-a", "A option", false, false);
  argparser_add(parser, "-b", "--option-b", "B option", false, true);
  argparser_from_struct(parser, &opt_c);
  argparser_from_struct(parser, &opt_d);

  argparser_parse(parser, argc, argv);
  argparser_dump(parser);
  argparser_validate(parser);
  argparser_usage(parser);

  argparser_free(parser);

  return 0;
}
