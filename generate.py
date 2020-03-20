# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generate.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacharle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 18:13:26 by cacharle          #+#    #+#              #
#    Updated: 2020/02/06 19:36:46 by cacharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os
import sys
import argparse
import string
import subprocess
from random import randrange, choice, shuffle


INT_MIN = -2147483648
INT_MAX = 2147483647
UINT_MAX = 4294967295
CHAR_MIN = -128
CHAR_MAX = 127
ULONG_INT_MAX = 18446744073709551616

CHARS = (list(string.ascii_lowercase) + list(string.ascii_uppercase)
        + list(string.punctuation) + list(string.digits))
CHARS.remove("\"")
CHARS.remove("\\")
CHARS.extend([r"\t", r"\n", r"\r", r"\v", r"\f", "\\\\"])


def parse_args():
    parser = argparse.ArgumentParser(prog="ft_printf_test generator", description="A random  test generator")
    parser.add_argument("-n", "--tests", type=int, default=100, help="number of tests to generate")
    parser.add_argument("-c", "--check-gcc", action="store_true", help="check generated test is valid with gcc (slow)")
    parser.add_argument("-o", "--output", default="generated.c", help="output file")
    parser.add_argument("-a", "--args-max", default=5, type=int, help="maximum number of argument")
    parser.add_argument("-f", "--flags-max",  default=3, type=int, help="maximum number of flags")
    parser.add_argument("-s", "--str-max",  default=30, type=int, help="maximum length of string")
    parser.add_argument("--bonus",  action="store_true",  help="generate with bonus flags")
    return vars(parser.parse_args(sys.argv[1:]))


class Generator:
    def __init__(self, options):
        self.test_nb = options["tests"]
        self.check_valid = options["check_gcc"]
        self.output_filename = options["output"]
        self.output_file = None
        self.tmp_filename = "tmp.c"
        self.args_max = options["args_max"]
        self.flags_max = options["flags_max"]
        self.str_max_len = options["str_max"]
        self.width_max = 200
        self.width_wildcard_rate = 10
        self.width_empty_rate = 2
        self.precision_max = 200
        self.precision_wildcard_rate = 10
        self.precision_empty_rate = 2
        self.precision_point_rate = 4
        self.possible_conv ="diuxXcsp%"
        if options["bonus"]:
            self.possible_flags = "#0- +'"
        else:
            self.possible_flags = "0-"
        self.possible_conv_len = len(self.possible_conv)
        self.pool = []

    def run(self):
        if self.check_valid:
            os.system("touch {}".format(self.tmp_filename))
        with open(self.output_filename, "w") as self.output_file:
            self._write_header()
            while self.test_nb > 0:
                assert_printf = self._gen_printf()
                if self.check_valid and not self._compile(assert_printf):
                    print("Failed to generate:", assert_printf)
                    continue
                self.test_nb -= 1
                self.output_file.write(assert_printf + "\n\t")
                print("Generated", self.test_nb)
            self._write_footer()
        if self.check_valid:
            os.system("rm {}".format(self.tmp_filename))

    def _compile(self, assert_printf):
        with open(self.tmp_filename, "w") as tmp_file:
            tmp_file.write("#include <stdio.h>\n#include \"header.h\"\nvoid t (){")
            tmp_file.write(assert_printf + "}")
        return os.system("gcc -c -Wformat -Werror tmp.c > /dev/null 2>&1") == 0

    def _gen_printf(self):
        formats, args = self._printf_args()
        args_str = "".join(["," + str(a) for a in args if a is not None])
        return "ASSERT_PRINTF(\"{}\" {});".format(''.join(formats), args_str)

    def _printf_args(self):
        args = []
        formats = []
        for _ in range(randrange(1, self.args_max + 1)):
            conv = self.possible_conv[randrange(self.possible_conv_len)]
            f = self._fmt(conv)
            for _ in range(f.count("*")):
                args.append(randrange(-200, 200))
            formats.append(f)
            a = self._arg(conv)
            if a == "\"NULL\"":
                a = "NULL"
            args.append(a)
        return formats, args

    def _fmt(self, conv):
        return "%" + self._flags(conv) + self._width() + self._precision(conv) + conv

    def _arg(self, conv):
        return {
            'c': randrange(CHAR_MIN, CHAR_MAX + 1),
            's': "\"" + self._gen_string() + "\"",
            'd': randrange(INT_MIN, INT_MAX + 1),
            'i': randrange(INT_MIN, INT_MAX + 1),
            'u': str(randrange(UINT_MAX)) + "u",
            'x': str(randrange(UINT_MAX)) + "u",
            'X': str(randrange(UINT_MAX)) + "u",
            'p': "(void*)" + str(randrange(ULONG_INT_MAX)) + "lu",
            '%': None
        }[conv]

    def _flags(self, conv):
        return self._filter_flags(
            "".join([choice(self.possible_flags)
                     for _ in range(randrange(1, self.flags_max + 1))]),
            conv
        )

    def _filter_flags(self, flags, conv):
        if "+" in flags and conv in "psxXcu":
            flags = flags.replace("+", "")
        if " " in flags and conv in "pcsuxX":
            flags = flags.replace(" ", "")
        if "0" in flags and conv in "pcs":
            flags = flags.replace("0", "")
        if "#" in flags and conv in "upcsdi":
            flags = flags.replace("#", "")
        if "'" in flags and conv not in "diu":
            flags = flags.replace("'", "")

        if "0" in flags and "-" in flags:
            flags = flags.replace("0", "")
        if " " in flags and "+" in flags:
            flags = flags.replace(" ", "")
        return flags

    def _width(self):
        p = randrange(100)
        if p < self.width_wildcard_rate:
            return "*"
        p -= self.width_wildcard_rate
        if p < self.width_empty_rate:
            return ""
        return str(randrange(1, self.width_max))

    def _precision(self, conv):
        if conv == "p" or conv == "c":
            return ""
        p = randrange(100)
        if p < self.precision_wildcard_rate:
            return ".*"
        p -= self.precision_wildcard_rate
        if p  < self.precision_empty_rate:
            return ""
        p -= self.precision_empty_rate
        if p < self.precision_point_rate:
            return "."
        return "." + str(randrange(self.precision_max))

    def _gen_string(self):
        if randrange(100) < 5:
            return "NULL"
        return "".join([choice(CHARS) for _ in range(randrange(self.str_max_len))])

    def _write_header(self):
        self.output_file.write("#include \"header.h\"\n\nvoid generated_test(void)\n{\n\t")

    def _write_footer(self):
        self.output_file.write("}\n")

if __name__ == "__main__":
    options = parse_args()
    g = Generator(options)
    g.run()
