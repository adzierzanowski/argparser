#ifndef TEST_H
#define TEST_H

#include "argparser.h"

struct argparser_t *parser; 

void create_parser(void)
{
  parser = argparser_new("test");
}

void destroy_parser(void)
{
  argparser_free(parser);
}

void add_option_a(void)
{
  argparser_add(parser, "-a", "--option-a", "Option A", false, false);
}

void add_option_b(void)
{
  argparser_add(parser, "-b", "--option-b", "Option B", false, true);
}

void add_option_c(void)
{
  argparser_add(parser, "-c", "--option-c", "Option C", true, false);
}

void add_option_d(void)
{
  argparser_add(parser, "-d", "--option-d", "Option D", true, true);
}

void add_option_a_struct(void)
{
  struct option_init_t opt_init = {
    .short_name = "-a",
    .long_name = "--option-a",
    .help = "Option A",
    .required = false,
    .takes_arg = false
  };
  argparser_from_struct(parser, &opt_init);
}

void add_option_b_struct(void)
{
  struct option_init_t opt_init = {
    .short_name = "-b",
    .long_name = "--option-b",
    .help = "Option B",
    .required = false,
    .takes_arg = true 
  };
  argparser_from_struct(parser, &opt_init);
}

void add_option_c_struct(void)
{
  struct option_init_t opt_init = {
    .short_name = "-c",
    .long_name = "--option-c",
    .help = "Option C",
    .required = true,
    .takes_arg = false 
  };
  argparser_from_struct(parser, &opt_init);
}

void add_option_d_struct(void)
{
  struct option_init_t opt_init = {
    .short_name = "-d",
    .long_name = "--option-d",
    .help = "Option D",
    .required = true,
    .takes_arg = true 
  };
  argparser_from_struct(parser, &opt_init);
}

#endif
