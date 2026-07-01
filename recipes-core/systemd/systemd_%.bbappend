PACKAGECONFIG:remove = " \
	serial-getty-generator \
"

RDEPENDS:${PN}:remove = "systemd-serialgetty"
