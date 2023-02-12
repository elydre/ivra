import os
import sys

CC      = "gcc"

OUTPUT  = "ivra.elf"

CFLAGS  = "-I ./include -Wall -Wextra"

OBJDIR  = "build"
SRCDIR  = "src"

CSOURCES = [e for e in os.listdir(SRCDIR) if e.endswith(".c")]

def execute_command(cmd):
    print(f"| {cmd}")
    rcode = os.system(cmd)
    if rcode == 0: return
    print(f"Command failed with exit code {rcode}")
    exit(rcode if rcode < 256 else 1)

def compile_file(src, dir = SRCDIR):
    obj = os.path.join(OBJDIR, f"{os.path.splitext(src)[0]}.o")
    cmd = f"{CC} -c {os.path.join(dir, src)} -o {obj} {CFLAGS}"
    execute_command(cmd)
    return obj

def link_files(entry, objs):
    execute_command(f"{CC} {entry} {' '.join(objs)} -o {OUTPUT}")

def build():
    print("==== BUILDING ====")
    execute_command(f"mkdir -p {OBJDIR}")
    objs = [compile_file(src) for src in CSOURCES]

    entry = compile_file("entry.c", ".")
    link_files(entry, objs)

def build_run():
    build()
    print("\n==== RUNNING ====")
    execute_command(f"./{OUTPUT}")

def clean():
    execute_command(f"rm -rf {OBJDIR} {OUTPUT}")

def show_help():
    print("Usage: build.py [options]")
    print("Options:")
    print("  -h  Show this help")
    print("  -c  Clean build directory")
    print("  -r  Build and run")

match_table = {
    "-h": show_help,
    "-c": clean,
    "-r": build_run,
}

if __name__ == "__main__":
    args = sys.argv[1:]
    if len(args) == 0:
        build()
    else:
        for arg in args:
            if arg in match_table:
                match_table[arg]()
            else:
                print(f"Unknown argument {arg}")
                show_help()

    