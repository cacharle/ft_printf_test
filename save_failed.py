if __name__ == "__main__":
    error_lines = []
    with open("result.log") as logs:
        for line in logs:
            if line.find("OUTPUT") != -1 or line.find("SEGFAULT") != -1:
                error_lines.append(line)

    for i, l in enumerate(error_lines):
        error_lines[i] = l[l.find("ft_printf") + 9:].strip()

    try:
        with open("saved_tests.c", "r") as save_file:
            previous_lines = save_file.readlines()[4:-1]
    except FileNotFoundError:
        previous_lines = []

    with open("saved_tests.c", "w") as save_file:
        save_file.write("#include \"header.h\"\n\nvoid saved_test(void)\n{\n\t")
        for l in previous_lines:
            save_file.write(l)
        for l in error_lines:
            save_file.write(f"ASSERT_PRINTF{l}\n\t")
        save_file.write("}\n")
