import os
import sys
import argparse


def parse_args():
    parser = argparse.ArgumentParser(prog="ft_printf_test generator", description="A random  test generator")
    parser.add_argument("-n", help="number of tests to generate", type=int)
    parser.add_argument("-q", "--quiet",
                        help="decrease vebosity", action="store_true")
    parser.add_argument("-c", "--no-clear", help="disable terminal clear before output")
    parser.add_argument("-f", "--output-file", help="output file name", default="tests/generated.c"))
    return vars(parser.parse_args(sys.argv[1:]))


if __name__ == "__main__":
    pass
