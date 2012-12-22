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

