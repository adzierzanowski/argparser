#include <criterion/criterion.h>
#include "test.h"


Test(parsing, short_a_passed, .init=create_parser_with_options, .fini=destroy_parser)
{
  argparser_parse(parser, argc, (char **) argv);
  cr_expect(argparser_passed(parser, "-a"), "Expected -a to be passed.");
}

Test(parsing, short_b_passed, .init=create_parser_with_options, .fini=destroy_parser)
{
  argparser_parse(parser, argc, (char **) argv);
  cr_expect(argparser_passed(parser, "-b"), "Expected -b to be passed.");
}

Test(parsing, short_c_passed, .init=create_parser_with_options, .fini=destroy_parser)
{
  argparser_parse(parser, argc, (char **) argv);
  cr_expect(argparser_passed(parser, "-c"), "Expected -c to be passed.");
}

Test(parsing, short_d_not_passed, .init=create_parser_with_options, .fini=destroy_parser)
{
  argparser_parse(parser, argc, (char **) argv);
  cr_expect(
    argparser_passed(parser, "-d") == false,
    "Expected -d not to be passed."
  );
}

Test(parsing, long_a_passed, .init=create_parser_with_options, .fini=destroy_parser)
{
  argparser_parse(parser, argc, (char **) argv);
  cr_expect(
    argparser_passed(parser, "--option-a"),
    "Expected --option-a to be passed."
  );
}

Test(parsing, long_b_passed, .init=create_parser_with_options, .fini=destroy_parser)
{
  argparser_parse(parser, argc, (char **) argv);
  cr_expect(
    argparser_passed(parser, "--option-b"),
    "Expected --option-b to be passed."
  );
}

Test(parsing, long_c_passed, .init=create_parser_with_options, .fini=destroy_parser)
{
  argparser_parse(parser, argc, (char **) argv);
  cr_expect(
    argparser_passed(parser, "--option-c"),
    "Expected --option-c to be passed."
  );
}

Test(parsing, long_d_not_passed, .init=create_parser_with_options, .fini=destroy_parser)
{
  argparser_parse(parser, argc, (char **) argv);
  cr_expect(
    argparser_passed(parser, "--option-d") == false,
    "Expected --option-d not to be passed."
  );
}

Test(parsing, short_b_value, .init=create_parser_with_options, .fini=destroy_parser)
{
  argparser_parse(parser, argc, (char **) argv);
  cr_expect_str_eq(
    argparser_get(parser, "-b"), "b_arg",
    "Expected -b value to be 'b_arg' but got '%s'.", argparser_get(parser, "-b")
  );
}

Test(parsing, long_b_value, .init=create_parser_with_options, .fini=destroy_parser)
{
  argparser_parse(parser, argc, (char **) argv);
  cr_expect_str_eq(
    argparser_get(parser, "--option-b"), "b_arg",
    "Expected --option-b value to be 'b_arg' but got '%s'.",
    argparser_get(parser, "--option-b")
  );
}

Test(parsing, passed_count, .init=create_parser_with_options, .fini=destroy_parser)
{
  int passed_cnt = argparser_parse(parser, argc, (char **) argv);
  cr_expect(
    passed_cnt == 3,
    "Expected 3 of defined arguments to be passed, got %d.", passed_cnt
  );
}
