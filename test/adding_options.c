#include <criterion/criterion.h>
#include "test.h"


Test(adding_options, creation, .init=create_parser, .fini=destroy_parser)
{
  add_option_a();
  add_option_b();
  add_option_c();
  cr_assert(parser->count == 3, "Expected parser->count to be 3.");
}

Test(adding_options, short_name, .init=create_parser, .fini=destroy_parser)
{
  add_option_a();
  cr_expect_str_eq(
    parser->options[0]->short_name, "-a", "Expected short name to be '-a'.");
}

Test(adding_options, long_name, .init=create_parser, .fini=destroy_parser)
{
  add_option_a();
  cr_expect_str_eq(
    parser->options[0]->long_name, "--option-a",
    "Expected short name to be '--option-a'."
  );
}

Test(adding_options, help, .init=create_parser, .fini=destroy_parser)
{
  add_option_a();
  cr_expect_str_eq(
    parser->options[0]->help, "Option A",
    "Expected help string to be 'Option A'."
  );
}

Test(adding_options, required_false, .init=create_parser, .fini=destroy_parser)
{
  add_option_a();
  cr_expect(
    parser->options[0]->required == false,
    "Expected -a not to be required."
  );
}

Test(adding_options, required_true, .init=create_parser, .fini=destroy_parser)
{
  add_option_c();
  cr_expect(
    parser->options[0]->required == true,
    "Expected -c to be required."
  );
}

Test(adding_options, takes_arg_false, .init=create_parser, .fini=destroy_parser)
{
  add_option_a();
  cr_expect(
    parser->options[0]->takes_arg == false,
    "Expected -a not to take argument."
  );
}

Test(adding_options, takes_arg_true, .init=create_parser, .fini=destroy_parser)
{
  add_option_b();
  cr_expect(
    parser->options[0]->takes_arg == true,
    "Expected -b to take argument."
  );
}
