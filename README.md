# Beaglebone Black IO.

This is a playground for accessing analog inputs and digital inputs and outputs on a Beaglebone Black board.

The "vendors" directory includes the [libpruio library](http://www.freebasic.net/forum/viewtopic.php?f=14&t=22501) and its dependencies. Libpruio uses one of the [PRUs](https://github.com/beagleboard/am335x_pru_package/blob/master/Documentation/01-AM335x_PRU_ICSS_Overview.p) available in the BBB to perform io operations.

The "device-tree-overlay" directory includes a DTO for configuring BBB pins and for enabling the PRU system. This will not be neessary with future versions of libpruio.

The "app" directory includes an example application written in C.

## Test results.

I have tested all the pins in the P9 header using this app and here are my findings:

These pins work just fine for input and output: P9_11, P9_12, P9_13, P9_14, P9_15, P9_16 P9_21, P9_22, P9_23, P9_24, P9_26, P9_27, P9_30, P9_42.


These work fine as outputs but not as inputs, when the overlay is loaded, the pin mode is not actually changed in /sys/kernel/debug/pinctrl/44e10800.pinmux/pins: P9_17, P9_18.

These one works fine as an input but when working as an output, will give 1.3 Volts instead of 3.3: P9_41.

I haven't tested P8 pins yet.

## License

Beaglebone Black IO. 
Copyright (C) 2014 Rafael Vega <rvega@elsoftwarehamuerto.org>

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
