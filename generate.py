import os
import sys
import argparse
import string
from random import randrange, choice, shuffle


INT_MIN = -2147483648
INT_MAX = 2147483647
UINT_MAX = 4294967295
CHAR_MIN = -128
CHAR_MAX = 127

ULONG_INT_MAX = 18446744073709551616

chars = (list(string.ascii_lowercase) + list(string.ascii_uppercase)
        + list(string.punctuation) + list(string.digits))
chars.remove("\"")
chars.remove("\\")
chars.extend([r"\t", r"\n", r"\r", r"\v", r"\f", "\\\\"])

def parse_args():
    parser = argparse.ArgumentParser(prog="ft_printf_test generator", description="A random  test generator")
    parser.add_argument("-n", help="number of tests to generate", type=int, default=100)
    return vars(parser.parse_args(sys.argv[1:]))

def random_string(n):
    b =  "".join([choice(chars) for _ in range(randrange(n))])
    return b

def random_flags():
    flags = ""
    possible = "#0- +'"
    for _ in range(randrange(len(possible))):
        flags += choice(possible)
    return flags

def random_width():
    r = randrange(100)
    if r < 5:
        return "*"
    elif r < 10:
        return ""
    return str(randrange(200))

def random_precision():
    r = randrange(100)
    if r < 5:
        return ".*"
    elif r < 10:
        return ""
    elif r < 12:
        return "."
    return "." + str(randrange(200))

def generate_args():
    a = []
    b = []
    fmt_str ="diuxXcsp%"
    for _ in range(15):
        t = fmt_str[randrange(len(fmt_str))]
        a.append(f"%{random_flags()}{random_width()}{random_precision()}{t}")
        b.append({
            'c': randrange(CHAR_MIN, CHAR_MAX + 1),
            's': "\"" + random_string(10) + "\"",
            'd': randrange(INT_MIN, INT_MAX + 1),
            'i': randrange(INT_MIN, INT_MAX + 1),
            'u': randrange(UINT_MAX),
            'x': randrange(UINT_MAX),
            'X': randrange(UINT_MAX),
            'p': str(randrange(ULONG_INT_MAX)) + "lu",
            '%': None
        }[t])
    return a, b


def generate_printf():
    a, b = generate_args()
    s = "\""
    s2 = ""
    for x, y in zip(a, b):
        s += x
        if x[-1] != '%':
            s2 += "," + str(y)

    return f"ASSERT_PRINTF({s}\" {s2});"



if __name__ == "__main__":
    options = parse_args()
    nb_tests = options["n"]
    with open("generated.c", "w") as file:
        file.write("#include \"header.h\"\n\nvoid generated_test(void)\n{\n\t")

        while nb_tests > 0:
            with open("tmp.c", "w") as tmp:
                tmp.write("#include <stdio.h>\n#include \"header.h\"\nvoid t (){")
                tmp_assert = generate_printf()
                tmp.write(tmp_assert + "}")
            ret = os.system("gcc -c -Wall -Wextra -Werror tmp.c > /dev/null 2>&1")
            print(ret)
            if ret == 0:
                file.write(tmp_assert + "\n\t")
                nb_tests -= 1

        file.write("}\n")
