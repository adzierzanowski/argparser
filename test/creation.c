#include <criterion/criterion.h>
#include "test.h"

Test(creation, creation, .init=create_parser, .fini=destroy_parser)
{
  cr_assert_not_null(parser, "Expected parser not to be null.");
}

Test(creation, prog_name, .init=create_parser, .fini=destroy_parser)
{
  cr_expect_str_eq(
    parser->prog_name,
    "test",
    "Expected program name to be 'test' but is '%s'.", parser->prog_name);
}

Test(creation, options, .init=create_parser, .fini=destroy_parser)
{
  cr_expect_null(parser->options, "Expected parser.options to be NULL.");
}

Test(creation, positional_count, .init=create_parser, .fini=destroy_parser)
{
  cr_expect(
    parser->positional_count == 0,
    "Expected positional count to be 0 but is %d.", parser->positional_count);
}

Test(creation, positional, .init=create_parser, .fini=destroy_parser)
{
  cr_expect_null(
    parser->positional,
    "Expected parser.positional to be NULL.");
}
