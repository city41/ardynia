CPPFLAGS += -DSERIAL_LOG=0

ARDUINO_DIR = $(HOME)/.arduino_ide
ARDMK_DIR = $(HOME)/.arduino_mk
BOARD_TAG = leonardo

LOCAL_CPP_SRCS = $(wildcard src/*.cpp) $(wildcard src/entities/*.cpp)

include $(ARDMK_DIR)/Arduino.mk

emu: build-leonardo/ardynia.hex
	pabe build-leonardo/ardynia.hex

bmp:
	node ./bmptool/ --src spritePngs --dest src/spriteBitmaps.h --type combined && \
    node ./bmptool/ --src tilePngs --dest src/tileBitmaps.h --type bitmap

map:
	node ./maptool/ -s tiled -o src

strings:
	node ./stringtool/ -s strings.json -o src/strings.h
