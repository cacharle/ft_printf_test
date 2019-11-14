# ft_printf test

Unit test for the ft_printf project of 42 school.

![example_screenshot](./screenshot.png)

## Usage

Clone this repo such that:

```
`
|- ft_printf_test/
|- ft_printf/
```

or modify the `FT_PRINTF_PATH` variable in the Makefile

- `> make run`: run the tests in a pretty format
- `> make verbose`: to show a more verbose output
- `> make quiet`: to show a more quiet output
- `> make raw`: run the tests in a ugly but parsable format
- `> python3 prettier -h`: show prettier options
- `> make generate`: generate 100 random test 


## Random Test Generator

It will generate random test according to the `-Wformat` flag of gcc.

- `> python3 generate.py -n [number of tests]`: generate n test
- `> python3 generate.py -h`: show all available options

## Memory leaks check

You have to install [valgrind](http://valgrind.org/) with [brew](https://brew.sh/),
[here](https://stackoverflow.com/questions/35775102) is a nice thread to install it
locally if you don't have root access. You can then run `> brew install valgrind`.

- `> make check_leaks`: run valgrind on a test (without the test themself).
- `> make check_leaks_verbose`: add `--leak-check=full` to valgrind.

## Pro tips

This doesnt handle timeout, so if your `ft_printf` goes in an infinite loop,
this test will too.
`Ctrl-C` is your best friend.
