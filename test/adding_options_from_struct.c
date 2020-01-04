#include <criterion/criterion.h>
#include "test.h"


Test(adding_options_from_struct, creation, .init=create_parser, .fini=destroy_parser)
{
  add_option_a_struct();
  add_option_b_struct();
  add_option_c_struct();
  add_option_d_struct();
  cr_assert(parser->count == 4, "Expected parser->count to be 4.");
}

Test(adding_options_from_struct, short_name, .init=create_parser, .fini=destroy_parser)
{
  add_option_a_struct();
  cr_expect_str_eq(
    parser->options[0]->short_name, "-a",
    "Expected short name to be '-a'."
  );
}

Test(adding_options_from_struct, long_name, .init=create_parser, .fini=destroy_parser)
{
  add_option_a_struct();
  cr_expect_str_eq(
    parser->options[0]->long_name, "--option-a",
    "Expected short name to be '--option-a'."
  );
}

Test(adding_options_from_struct, help, .init=create_parser, .fini=destroy_parser)
{
  add_option_a_struct();
  cr_expect_str_eq(
    parser->options[0]->help, "Option A",
    "Expected help string to be 'Option A'."
  );
}

Test(adding_options_from_struct, required_false, .init=create_parser, .fini=destroy_parser)
{
  add_option_a_struct();
  cr_expect(
    parser->options[0]->required == false, "Expected -a not to be required."
  );
}

Test(adding_options_from_struct, required_true, .init=create_parser, .fini=destroy_parser)
{
  add_option_c_struct();
  cr_expect(
    parser->options[0]->required == true, "Expected -c to be required."
  );
}

Test(adding_options_from_struct, takes_arg_false, .init=create_parser, .fini=destroy_parser)
{
  add_option_a_struct();
  cr_expect(
    parser->options[0]->takes_arg == false, "Expected -a not to take argument."
  );
}

Test(adding_options_from_struct, takes_arg_true, .init=create_parser, .fini=destroy_parser)
{
  add_option_b_struct();
  cr_expect(
    parser->options[0]->takes_arg == true, "Expected -b to take argument."
  );
}
