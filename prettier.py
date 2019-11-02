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
                "expected": sys.stdin.readline().rstrip(),
                "actual": sys.stdin.readline().rstrip()
            })
            print(red("!"), end="")
        sys.stdout.flush()
    return logs


# def write_logs(logs):

def print_logs(logs):
    total_str = f"\n\nTotal     {green('OK: ', logs['ok'])}  {red('KO: ', logs['ko'])}"
    print(total_str)
    print("=" * (len(total_str) - len(green("")) * 2 - len(red("")) * 2 - 2))

    for ko in logs["ko_info"]:
        print(ko["msg"])
        print("   ", ko["expected"])
        print("   ", ko["actual"])
        print()


if __name__ == "__main__":
    print()
    logs = parse()
    # write_logs(logs)
    print_logs(logs)
