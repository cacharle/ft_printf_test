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
    parser = argparse.ArgumentParser(
        prog="ft_printf_test generator", description="A random  test generator")
    parser.add_argument("-n", type=int, default=100,
                        help="number of tests to generate")
    return vars(parser.parse_args(sys.argv[1:]))

class Generator:
    def __init__(self, options):
        self.test_nb = options["n"]
        self.output_filename = "generated.c"
        self.output_file = None
        self.tmp_filename = "tmp.c"
        self.str_max_len = 10
        self.args_max = 10
        self.flags_max = 2
        self.width_max = 200
        self.width_wildcard_rate = 10
        self.width_empty_rate = 2
        self.precision_max = 200
        self.precision_wildcard_rate = 10
        self.precision_empty_rate = 2
        self.precision_point_rate = 4
        self.possible_flags = "#0- +"
        self.possible_conv ="diuxXcsp"
        self.possible_conv_len = len(self.possible_conv)
        self.pool = []

    def run(self):
        with open(self.output_filename, "w") as self.output_file:
            self._write_header()
            while self.test_nb > 0:
                assert_printf = self._random_printf()
                print(assert_printf)
                # self.test_nb -= 1
                if self._compile(assert_printf):
                    self.output_file.write(assert_printf + "\n\t")
                    self.test_nb -= 1
                    print("generated")
            self._write_footer()
        os.system(f"rm {self.tmp_filename}")

    def quit(self):
        pass


    def _compile(self, assert_printf):
        with open(self.tmp_filename, "w") as tmp_file:
            tmp_file.write("#include <stdio.h>\n#include \"header.h\"\nvoid t (){")
            tmp_file.write(assert_printf + "}")
        return os.system("gcc -c -Wformat -Werror tmp.c > /dev/null 2>&1") == 0

    def _random_printf(self):
        formats, args = self._random_args()
        args_str = "".join(["," + str(a) for a in args if a is not None])
        return f"ASSERT_PRINTF(\"{''.join(formats)}\" {args_str});"

    def _random_args(self):
        args = []
        formats = []
        for _ in range(randrange(1, self.args_max + 1)):
            conv = self.possible_conv[randrange(self.possible_conv_len)]
            f = self._random_fmt(conv)
            for _ in range(f.count("*")):
                args.append(randrange(-100, 100))
            formats.append(f)
            args.append(self._random_arg(conv))
        return formats, args

    def _random_fmt(self, conv):
        return f"%{self._random_flags()}{self._random_width()}{self._random_precision()}{conv}"

    def _random_arg(self, conv):
        return {
            'c': randrange(CHAR_MIN, CHAR_MAX + 1),
            's': "\"" + self._random_string() + "\"",
            'd': randrange(INT_MIN, INT_MAX + 1),
            'i': randrange(INT_MIN, INT_MAX + 1),
            'u': randrange(UINT_MAX),
            'x': randrange(UINT_MAX),
            'X': randrange(UINT_MAX),
            'p': str(randrange(ULONG_INT_MAX)) + "lu"
            # '%': None
        }[conv]

    def _random_flags(self):
        if self.flags_max <= 0:
            return ""
        return "".join([choice(self.possible_conv) for _ in range(randrange(self.flags_max))])

    def _random_width(self):
        p = randrange(100)
        if p < self.width_wildcard_rate:
            return "*"
        p -= self.width_wildcard_rate
        if p < self.width_empty_rate:
            return ""
        return str(randrange(self.width_max))

    def _random_precision(self):
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

    def _random_string(self):
        return "".join([choice(CHARS) for _ in range(randrange(self.str_max_len))])

    def _write_header(self):
        self.output_file.write("#include \"header.h\"\n\nvoid generated_test(void)\n{\n\t")

    def _write_footer(self):
        self.output_file.write("}\n")

if __name__ == "__main__":
    options = parse_args()
    g = Generator(options)
    try:
        g.run()
    except KeyboardInterrupt:
        pass
    finally:
        g.quit()
