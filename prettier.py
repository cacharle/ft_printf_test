import sys

def green(*strings):
    return "".join([f"\033[32m{s}\033[0m" for s in strings])

def red(*strings):
    return "".join([f"\033[31m{s}\033[0m" for s in strings])


def parse():
    logs = {
        "ok": 0,
        "ko": 0,
        "ko_info": []
    }

    for line in sys.stdin:
        line = line.strip()
        if line.find("[OK]") != -1:
            logs["ok"] += 1
            print(green("."), end="")
        elif line.find("[KO]") != -1:
            logs["ko"] += 1
            logs["ko_info"].append({
                "msg": line[line.find("[KO]") + 5:],
                "expected": sys.stdin.readline(),
                "actual": sys.stdin.readline()
            })
            print(red("!"), end="")
        sys.stdout.flush()
    return logs


# def write_logs(logs):

def print_logs(logs):
    print(f"Total     {green('OK:', logs['ok'])}  {red('KO:', logs['ko'])}")

if __name__ == "__main__":
    logs = parse()
    print()
    # write_logs(logs)
    print_logs(logs)
