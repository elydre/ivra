import sys
import os

CC      = "gcc"
LD      = "ld"

OUTPUT  = "ivra"

CFLAGS  = "-g -ffreestanding -fno-exceptions -m32 -Wimplicit-function-declaration -I ./profan_libs -I ./include"
LDFLAGS = "-melf_i386 -e entry"

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
    execute_command(f"{LD} {LDFLAGS} -o {OUTPUT}.pe {entry} {' '.join(objs)} ")
    execute_command(f"objcopy -O binary {OUTPUT}.pe {OUTPUT}.bin")
    execute_command(f"rm {OUTPUT}.pe")

def build():
    print("==== BUILDING ====")
    execute_command(f"mkdir -p {OBJDIR}")
    objs = [compile_file(src) for src in CSOURCES]

    entry = compile_file("entry.c", ".")
    link_files(entry, objs)

def clean():
    execute_command(f"rm -rf {OBJDIR} {OUTPUT}.pe {OUTPUT}.bin")

def show_help():
    print("Usage: build.py [options]")
    print("Options:")
    print("  -h  Show this help")
    print("  -c  Clean build directory")

match_table = {
    "-h": show_help,
    "-c": clean,
    "-b": build,
}

def main():
    args = sys.argv[1:]

    if len(args) == 0:
        build()
        return 0

    for arg in args:
        if arg not in match_table:
            print(f"Unknown argument {arg}")
            show_help()
            return 1
        match_table[arg]()

    return 0

if __name__ == "__main__":
    sys.exit(main())
