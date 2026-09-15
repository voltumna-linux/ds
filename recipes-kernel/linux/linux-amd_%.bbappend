require recipes-kernel/linux/linux-production.inc

# The AMD installer hardcodes /lib/modules; use the kernel class's usrmerge-aware
# installer, including its cleanup of module build/source links.
do_install() {
    kernel_do_install
}

INSANE_SKIP:${KERNEL_PACKAGE_NAME}-modules:remove = "usrmerge"

# The AMD recipe packages /boot, but Voltumna installs boot files in /usr/boot.
FILES:${KERNEL_PACKAGE_NAME}-modules += "/${KERNEL_IMAGEDEST}"

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append:d-9755-h14dsh = " \
	file://vtd-amd.cfg \
        file://amd-extra.cfg \
        file://fix-build-error.patch \
	file://static_intel_drivers.cfg \
        file://nr-cpus-512.cfg \
        "

