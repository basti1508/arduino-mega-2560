AVR_DUDE = avrdude
AVR_MMCU = m2560
AVR_PROG = stk500v2

AVR_FLAGS = -c $(AVR_PROG) -P /dev/ttyACM0 -p $(AVR_MMCU)

MCU = atmega2560
CLOCK = 16000000

CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE = avr-size -C --mcu=$(MCU)

OPT = s

# Common Include Paths
TOP := $(dir $(lastword $(MAKEFILE_LIST)))
TOP := $(patsubst %/, %, $(TOP))
EXTRAINCDIRS = -I$(TOP) -I.
CPPFLAGS += $(EXTRAINCDIRS)

CPPFLAGS+= -D__AVR_ATmega328P__
CPPFLAGS+= -DF_CPU=${CLOCK}

CFLAGS += -mmcu=$(MCU) -O$(OPT)
CFLAGS += -Werror -Wextra
CFLAGS += -Wall -Wcast-align -Wimplicit
CFLAGS += -Wpointer-arith -Wswitch
CFLAGS += -Wredundant-decls -Wreturn-type -Wshadow -Wunused
CFLAGS += -funsigned-char
CFLAGS += -funsigned-bitfields
CFLAGS += -fpack-struct
