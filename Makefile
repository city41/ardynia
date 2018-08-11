ARDUINO_DIR = $(HOME)/.arduino_ide
ARDMK_DIR = $(HOME)/.arduino_mk
BOARD_TAG = leonardo

LOCAL_CPP_SRCS = $(wildcard *.cpp)

include $(ARDMK_DIR)/Arduino.mk
