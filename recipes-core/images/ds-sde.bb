require recipes-core/images/voltumna-sde.bb
require include/runtime.inc
require include/development.inc
VARIANT = "Device Server (Development)"

IMAGE_INSTALL:append = " users-development"
