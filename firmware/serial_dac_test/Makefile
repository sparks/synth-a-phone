# Author: Severin Smith

##Hardware##

DEVICE     = atmega328
CLOCK      = 20000000

FUSES      = -U efuse:w:0x07:m -U hfuse:w:0xD9:m -U lfuse:w:0xDF:m
PROGRAMMER = -c usbtiny -P usb

##Files/Directories##

NAME       = main
SRC_DIR    = src
BIN_DIR    = bin
SOURCES    = $(wildcard $(SRC_DIR)/*.c)
OBJECTS    = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SOURCES))
DOXY_CONF  = doxygen.conf

##Tools##

AVRDUDE = avrdude -v $(PROGRAMMER) -p $(DEVICE)
COMPILE = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)

##Main Targets##

all: $(BIN_DIR)/$(NAME).hex

#For XCode
install: flash

flash: all
	$(AVRDUDE) -U flash:w:$(BIN_DIR)/$(NAME).hex:i

fuse:
	$(AVRDUDE) $(FUSES)

docs:
	doxygen $(DOXY_CONF)

clean_doc:
	rm -rf doc/*

clean_bin:
	rm -f $(BIN_DIR)/*.hex $(BIN_DIR)/*.elf $(BIN_DIR)/*.o

clean: clean_bin clean_doc

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
$(SRC_DIR)/%.S: $(SRC_DIR)/%.c
	$(COMPILE) -S $< -o $@

##Other##

#Save intermediate files
.SECONDARY: