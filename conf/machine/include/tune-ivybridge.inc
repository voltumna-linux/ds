# Settings for the GCC(1) cpu-type "ivybridge":
#
#     Intel Ivy Bridge CPU with 64-bit extensions, MMX, SSE, SSE2, SSE3, SSSE3, SSE4.1,
#     SSE4.2, POPCNT, CX16, SAHF, FXSR, AVX, XSAVE, PCLMUL, FSGSBASE, RDRND 
#     and F16C instruction set support.
#
# This tune is recommended for Intel Ivybridge CPU (and beyond).
#
DEFAULTTUNE ?= "ivybridge-64"

# Include the previous tune to pull in PACKAGE_EXTRA_ARCHS
require conf/machine/include/x86/tune-corei7.inc

# Extra tune features
TUNEVALID[ivybridge] = "Enable ivybridge specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'ivybridge', ' -march=ivybridge ${IVYBRIDGE_TUNE} -mfpmath=sse', '', d)}"

# Extra tune selections
AVAILTUNES += "ivybridge-64"
TUNE_FEATURES:tune-ivybridge-64 = "${TUNE_FEATURES:tune-x86-64} ivybridge"
BASE_LIB:tune-ivybridge-64 = "lib64"
TUNE_PKGARCH:tune-ivybridge-64 = "ivybridge-64"
PACKAGE_EXTRA_ARCHS:tune-ivybridge-64 = "${PACKAGE_EXTRA_ARCHS:tune-corei7-64} ivybridge-64"
QEMU_EXTRAOPTIONS_ivybridge-64 = " -cpu IvyBridge-v2"

IVYBRIDGE_TUNE .= "${@bb.utils.contains('MACHINE_FEATURES', 'qemu-usermode', ' ${QEMU_UNAVAILABLE_ISA}', '-mtune=generic -mavx2', d)}"

QEMU_UNAVAILABLE_ISA = " \
-mno-avx \
-mno-avx2 \
-mno-avx512f \
-mno-avx512cd \
-mno-avx512dq \
-mno-avx512bw \
-mno-avx512vl \
-mno-avx512ifma \
-mno-avx512vbmi \
-mno-avx512vbmi2 \
-mno-avx512vnni \
-mno-avx512bitalg \
"
