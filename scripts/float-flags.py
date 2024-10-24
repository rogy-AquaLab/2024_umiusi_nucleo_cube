Import("env")

env.Append(CCFLAGS=['-mfpu=fpv4-sp-d16'], LINKFLAGS=['-mfpu=fpv4-sp-d16'])
