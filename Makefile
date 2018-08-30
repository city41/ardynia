CPPFLAGS += -DSERIAL_LOG=0

ARDUINO_DIR = $(HOME)/.arduino_ide
ARDMK_DIR = $(HOME)/.arduino_mk
BOARD_TAG = leonardo

LOCAL_CPP_SRCS = $(wildcard *.cpp)

include $(ARDMK_DIR)/Arduino.mk

emu: build-leonardo/arduzel.hex
	pabe build-leonardo/arduzel.hex

bmp: pngs/*.png
	ardusprites --src pngs --dest bitmaps.h

map:
	node ./maptool/ -s ./tiled/ -o .

