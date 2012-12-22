How To Install and Use OpenOCD
==============================
<p>This document details how to compile the latest Open OCD from source and use it with Olimex's ARM-USB-OCD-H jtag programmer to program and debug Atmel's sam3u chip.  On OS X, you can also get everything from homebrew, though it is currently one version behind.</p>
<p>Open source tools are preffered over others</p>
<p>Open OCD and the other tools used will likely have dependencies which your system may or may not have - I advise you to read their respective READMEs</p>

OS X
----
<p>This procedure was tested on MBA running 10.8.2 - Mountain Lion</p>
  * get the libusb and libftdi drivers, either from source or from <code>brew install libusb libftdi</code>
    * note: D2XX ftdi drivers may be more stable, but are closed source; they can be aquired here: http://www.ftdichip.com/Drivers/D2XX.htm
    * check the README packged with them for installation instructions
  * checkout the Open OCD source, currently can be done by <code>git clone git://openocd.git.sourceforge.net/gitroot/openocd/openocd
  * bootstrap, configure and install:
    <pre><code>cd openocd
./bootstrap
./configure --enable-maintainer-mode --enable-ft2232_libftdi
sudo make install</code></pre>


### Homebrew
<p>If you use homebrew, the whole procedure can be simply done by:</p>
<pre><code>brew install libusb libftdi openocd --enable-ft2232_libftdi</code></pre>
note:
  * currently this installs version 0.6.1
  * you maybe have to change the permissions of <code>/usr/local/share/openocd/</code> so that brew can put Open OCD's startup scripts in there

Linux
-----


Compiling - Running - Debugging a Test Program
----------------------------------------------

