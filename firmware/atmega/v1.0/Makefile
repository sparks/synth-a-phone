# Author: Severin Smith

##Hardware##

DEVICE     = atmega328
CLOCK      = 20000000

FUSES      = -U efuse:w:0x07:m -U hfuse:w:0xD9:m -U lfuse:w:0xDF:m
PROGRAMMER = -c $(AVR_ISP) -P usb

##Files/Directories##

NAME       = main
SRC_DIR    = src
BIN_DIR    = bin
SOURCES    = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*.cpp)
ASMFILES   = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.S, $(SOURCES))
OBJECTS    = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SOURCES))
DOXY_CONF  = doxygen.conf

##Tools##

AVRDUDE = avrdude $(PROGRAMMER) -p $(DEVICE)
COMPILE = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)

##Main Targets##

all: bin_dir $(BIN_DIR)/$(NAME).hex size

asm: bin_dir $(ASMFILES)

#For XCode
install: flash

flash: all
	$(AVRDUDE) -U flash:w:$(BIN_DIR)/$(NAME).hex:i

fuse:
	$(AVRDUDE) $(FUSES)

doxygen: doc_dir
	doxygen $(DOXY_CONF)

size: bin_dir $(BIN_DIR)/$(NAME).hex
	avr-size $(BIN_DIR)/$(NAME).hex

bin_dir:
	@mkdir -p bin

doc_dir:
	@mkdir -p doc

clean_doxygen:
	rm -rf doc

clean_bin:
	rm -rf bin

clean: clean_bin clean_doxygen

##Specific Targets##

#Make elf file
$(BIN_DIR)/%.elf: $(OBJECTS)
	$(COMPILE) -o $@ $(OBJECTS)

#Make hex file
$(BIN_DIR)/%.hex: $(BIN_DIR)/%.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

##Generic Targets##

#Compile object files from c
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPILE) -c $< -o $@

#Compile object files from assembler
$(BIN_DIR)/%.o: $(SRC_DIR)/%.S
	$(COMPILE) -x assembler-with-cpp -c $< -o $@

#Compile assembler only
$(BIN_DIR)/%.S: $(SRC_DIR)/%.c
	$(COMPILE) -S $< -o $@

##Other##

#Save intermediate files
.SECONDARY:
