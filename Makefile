CPPFLAGS += -DSERIAL_LOG=1

ARDUINO_DIR = $(HOME)/.arduino_ide
ARDMK_DIR = $(HOME)/.arduino_mk
BOARD_TAG = leonardo

LOCAL_CPP_SRCS = $(wildcard *.cpp)

include $(ARDMK_DIR)/Arduino.mk

emu: build-leonardo/arduzel.hex
	pabe build-leonardo/arduzel.hex

bmp:
	node ./bmptool/ --src spritePngs --dest spriteBitmaps.h --type combined && \
    node ./bmptool/ --src tilePngs --dest tileBitmaps.h --type bitmap

map:
	node ./maptool/ -s ./tiled/ -o .

strings:
	node ./stringtool/ -s ./strings.json -o ./strings.h
