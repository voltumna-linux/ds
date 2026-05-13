FILESEXTRAPATHS:prepend := "${THISDIR}/linux-amd-6.18/linux-amd-6.18.28:"
SRCREV_meta = "4ad2f82ee14f9560019f67eb9ddcff1d9e2790f5"
SRCREV_machine = "c31b94a4231c974dca12e6b83f2af1d1d95dfc5e"

SRC_URI:append:naples := " \
           file://ntb.cfg \
           file://amd_io.cfg \
           file://prof.cfg \
           file://sdci.cfg \
           file://misc.cfg \
	  "

