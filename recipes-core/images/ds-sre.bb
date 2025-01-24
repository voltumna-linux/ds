require recipes-core/images/voltumna-sre.inc
require include/runtime.inc
VARIANT="Device Server (Runtime)"

IMAGE_INSTALL:append = " starter users net-snmp-client"
