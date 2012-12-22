How To Install and Use OpenOCD
==============================
<p>This document details how to compile the latest Open OCD from source and use it with Olimex's ARM-USB-OCD-H jtag programmer to program and debug Atmel's sam3u chip.  On OS X, you can also get everything from homebrew, though it is currently one version behind.</p>
<p>Open source tools are preffered over others</p>
<p>Open OCD and the other tools used will likely have dependencies which your system may or may not have - I advise you to read their respective READMEs</p>

OS X
----
<p>This procedure was tested on MBA running 10.8.2 - Mountain Lion</p>
<p>


### Homebrew
<p>If you use homebrew, the whole procedure can be simply done by:</p>
<pre><code>brew install libusb libftdi openocd --enable-ft2232_libftdi</code></pre>
<p>note:
  * currently this installs version 0.6.1
  * you maybe have to change the permissions of <code>/usr/local/share/openocd/</code> so that brew can put Open OCD's startup scripts in there
</p>


Linux
-----


Compiling - Running - Debugging a Test Program
----------------------------------------------

