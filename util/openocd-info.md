How To Install and Use OpenOCD
==============================
<p>This document details how to compile the latest Open OCD from source and use it with Olimex's ARM-USB-OCD-H jtag programmer to program and debug Atmel's sam3u chip.  On OS X, you can also get everything from homebrew, though it is currently one version behind.</p>
<p>Open source tools are preffered over others</p>
<p>Open OCD and the other tools used will likely have dependencies which your system may or may not have - I advise you to read their respective READMEs</p>

OS X
----
<p>This procedure was tested on 64 bit MBA running 10.8.2 - Mountain Lion</p>
  * get the libusb and libftdi drivers, either from source or from <code>brew install libusb libftdi</code>
    * note: D2XX ftdi drivers may be more stable, but are closed source; they can be aquired here: http://www.ftdichip.com/Drivers/D2XX.htm
    * check the README packged with them for installation instructions
  * checkout the Open OCD source, currently can be done by <code>git clone git://openocd.git.sourceforge.net/gitroot/openocd/openocd
  * bootstrap, configure and install:
    <pre><code>cd openocd
    ./bootstrap
    ./configure --enable-maintainer-mode --enable-ft2232_libftdi
    sudo make install</code></pre>
  * you can check with <code>openocd -v</code>, but this should currently get you version 0.7.x


### Homebrew
<p>If you use homebrew, the whole procedure can be simply done by:</p>
<pre><code>brew install libusb libftdi openocd --enable-ft2232_libftdi</code></pre>
  * currently this installs version 0.6.1
  * you maybe have to change the permissions of <code>/usr/local/share/openocd/</code> so that brew can put Open OCD's startup scripts in there

Linux
-----
<p>This procudure was tested on a 32 bit Ubuntu 12.04 running in a VM (OS X host).</p>
<p> I follow the install procedures found on this guide: http://www.seng.de/downloads/HowTo_ToolChain_STM32_Ubuntu.pdf except that I use the latest Open OCD version.</p>

  * get the dependencies:
    <pre><code>sudo apt-get install libftdi-dev libftdi1 libtool asciidoc \
    build-essential flex bison \
    libgmp3-dev libmpfr-dev autoconf \
    texinfo libncurses5-dev libexpat1 libexpat1-dev \
    tk tk8.4 tk8.4-dev</code></pre>
  * checkout the Open OCD source, currently can be done by <code>git clone git://openocd.git.sourceforge.net/gitroot/openocd/openocd
  * bootstrap, configure and install:
    <pre><code>cd openocd
    ./bootstrap
    ./configure --enable-maintainer-mode --enable-ft2232_libftdi
    make $PARALLEL
    sudo make install</code></pre>
  * you can check with <code>openocd -v</code>, but this should currently get you version 0.7.x


Compiling - Running - Debugging a Test Program
----------------------------------------------
### arm-none-eabi-gcc - Crosscompiler
<p>First things first, we'll need the crosscompiler.  If you're crafty, feel free to try and compile your own.  For now we'll just use the free to use Sourcery CodeBench from Mentor Graphics one as it is maintained up to date and also comes with some extra libs to make things easier.</p>
  * Linux/Windows - get it here: http://www.mentor.com/embedded-software/sourcery-tools/sourcery-codebench/editions/lite-edition/
    * look for the "Download the EABI Release" under "ARM processors" - since we're programming a bare-metal ARM chip
  * OS X - Mentor Graphics don't maintain an OS X build, but fortunately for us, these guys maintain one based on the Sourcery one: http://www.carlson-minot.com/available-arm-eabi-g-lite-builds-for-mac-os-x

### libs and Makefile
<p>Luckily, this guy, Pat Hickey, threw all the needed libs and Makefiles together for us already: https://github.com/pchickey/gcc-sam3u-build.  So you can just checkout his repo: <code>git clone git://github.com/pchickey/gcc-sam3u-build.git</code></p>
<p>However, we're using a different programmer than him, so:</p>
  * open the "openocd.cfg" file found in the root dir
  * change the first line from <code>source [find interface/jlink.cfg]</code> to <code>source [find interface/olimex-arm-usb-ocd-h.cfg]</code>

### test that everything works
<p>First, we'll test the the crosscomplier and makefiles work well.</P
  * cd into gcc-sam3u-build/simple
  * run 'make' to comile 'simple.elf'
  * there should be no errors or warnings

<p>Next, I'll just copy paste the instructions from Pat Hickey's repo:<p>
To check that openocd connects to the chip and flash the program:
> * Run openocd from a terminal at repository root (openocd.cfg present)
* In another terminal
  <pre><code>$ telnet localhost 4444</code></pre>
* In telnet session, the following commands will flash the chip with the program built in the simple/ directory:
  <pre><code>> halt
  > flash write_image simple/simple.elf
  > reset run
  > exit</code></pre>
* There seem to be issues with using "reset halt" to reset the SAM3 target. To reset the whole chip, write directly to the AIRCR system register with "mww 0xE000ED0C 0x05FA0007" For more info, see Section B.2.6 of the ARMv7-M Architecture Reference Manual.

To use openocd to debug simple.elf via gdb:
> * As before, run openocd from a terminal at the repository root
* In another terminal in simple/, run $ arm-none-eabi-gdb simple.elf
* In gdb:
  <pre><code>(gdb) target remote :3333
  (gdb) monitor halt
  (gdb) load
  (gdb) break main
  (gdb) continue
  ...
  Breakpoint 1, main () at simple.c:...
  (gdb) continue</code></pre>
* If gdb refuses to connect, follow the instructions above to connect to openocd via telnet, use just the "halt" command, then exit telnet. After that gdb should connect fine.
