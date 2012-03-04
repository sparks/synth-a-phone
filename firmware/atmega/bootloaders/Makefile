# Author: Severin Smith

#Make sure you set your programmer name and port correctly

PROGRAMMER = -c $(AVR_ISP) -P usb
AVRDUDE = avrdude $(PROGRAMMER) -p $(DEVICE)

ifeq ($(AVR_ISP), dragon_isp)
	SLEEP_DELAY = 2
else
	SLEEP_DELAY = 0
endif

##Targets##

all:

usbserial: DEVICE     = m8u2
usbserial: FUSES      = -U lfuse:w:0xFF:m -U hfuse:w:0xD9:m -U efuse:w:0xF4:m
usbserial:
	$(AVRDUDE) $(FUSES)
	sleep $(SLEEP_DELAY)
	$(AVRDUDE) -U flash:w:UNO-dfu_and_usbserial_combined.hex:i

HIDuino: DEVICE     = m8u2
HIDuino: FUSES      =  -U lfuse:w:0xFF:m -U hfuse:w:0xD9:m -U efuse:w:0xF4:m
HIDuino:
	$(AVRDUDE) $(FUSES)
	sleep $(SLEEP_DELAY)
	$(AVRDUDE) -U flash:w:HIDUINO_MIDI.hex:i

MocoLUFA: DEVICE     = m8u2
MocoLUFA: FUSES      =  -U lfuse:w:0xFF:m -U hfuse:w:0xD9:m -U efuse:w:0xF4:m
MocoLUFA:
	$(AVRDUDE) $(FUSES)
	sleep $(SLEEP_DELAY)
	$(AVRDUDE) -U flash:w:MIDI.hex:i


uno: DEVICE     = atmega328
uno: FUSES      =  -U lfuse:w:0xFF:m -U hfuse:w:0xDE:m -U efuse:w:0x05:m
uno:
	$(AVRDUDE) $(FUSES)
	sleep $(SLEEP_DELAY)
	$(AVRDUDE) -U flash:w:optiboot_atmega328.hex:i

propinq_patch: DEVICE     = atmega328p
propinq_patch: FUSES      =  -U lfuse:w:0xC2:m -U hfuse:w:0xDA:m -U efuse:w:0x05:m
propinq_patch:
	$(AVRDUDE) $(FUSES)
	sleep $(SLEEP_DELAY)
	$(AVRDUDE) -U flash:w:ATmegaBOOT_168_atmega328_pro_8MHz.hex:i

sketch: DEVICE     = atmega328
sketch:
	$(AVRDUDE) -U flash:w:/var/folders/m5/rj74pwk92571b5_971yq9d9r0000gn/T/build201609046512475145.tmp/helloworld.cpp.hex:i
