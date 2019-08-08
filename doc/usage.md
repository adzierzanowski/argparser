# argparser

## Basic usage

First of all, you have to initialize `argparser_t` struct using
`argparser_new` function, passing your program name as the first argument.

```c
struct argparser_t *parser = argparser_new("my_program");
```

Then you can define expected switches. You can do it in two ways.

### First method

```c
argparser_add(
  "-h",                               // short name
  "--help",                           // long name
  "Show this help message and exit",  // help text
  false,                              // required?
  false                               // takes an argument?
);
```

This method is shorter but less verbose. If you want, you can define options
by passing an initialization struct.

### Second method

```c
struct option_init_t opt_init = {
  .short_name = "-h",
  .long_name = "--help",
  .help = "Show this help message and exit",
  .required = false,
  .takes_arg = false
};

argparser_from_struct(parser, &opt_init);
```

### Parsing

After defining expected switches, you need to parse the command line.

```c
int passed_count = argparser_parse(parser, argc, argv);
```

`passed_count` return value represents the number of passed arguments from the
defined set.
