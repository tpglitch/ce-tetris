# ----------------------------
# Program Options
# ----------------------------

NAME         ?= TETRIS
ICON         ?= icon.png
DESCRIPTION  ?= "t e t r i s"
MAIN_ARGS    ?= NO
COMPRESSED   ?= NO
ARCHIVED     ?= NO

# ----------------------------
# Compile Options
# ----------------------------

OPT_MODE     ?= -Oz
EXTRA_CFLAGS ?= -Wall -Wextra

# ----------------------------
# Debug Options
# ----------------------------

OUTPUT_MAP   ?= NO

include $(shell cedev-config --makefile)
