# argparser

Really simple C argument parser. All values must be further converted to other
types by a programmer.

## caveats

String parameters in the parser struct are pointers to `argv`
so there is no need to deallocate them. E.g.:

```c
const char *param = argparser_get(parser, "--argument");
```

## usage

[See docs](doc/usage.md)
