import os
Import("env")

def after_build(source, target, env):
    objdump = env.subst("${OBJCOPY}").replace("objcopy", "objdump")
    src_elf = env.subst("\"${BUILD_DIR}\\${PROGNAME}.elf\"")
    cmd = " ".join([objdump, "-SC", "--file-start-context", "-w", src_elf, ">", "${PROGNAME}.lst"])
    env.Execute(cmd)

env.AddCustomTarget(
    "disasm",
    "${BUILD_DIR}/${PROGNAME}.elf",
    after_build,
    title="Disassemble Firmware",
    description="Generate a disassembly file on demand",
    always_build=True
)