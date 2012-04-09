# Makin' waves, yo.

import math
import argparse
import matplotlib.pyplot as plot

# Parse dem args.
parser = argparse.ArgumentParser(description='Generate wave table for sine of specified length and amplitude.')
parser.add_argument('-l', '--length', action='store', dest='len', type=int, help='length of the wave table.')
parser.add_argument('-a', '--amplitude', action='store', dest='amp', type=int, help='amplitude of the output waves.')

args = parser.parse_args()

len = args.len
amp = args.amp

# Generate dem wavetables.
sine = []

for i in range(len):
	sine.append(int(round(amp * math.sin(i * (1.0/len) * 2 * math.pi))))

# Write dat file.
f = open('wavetable_sin' + str(len) + '.h', 'w')

f.write('\n// Sine wave table of length ' + str(len) + ' from ' + str(amp) + ' to ' + str(-amp) + '\n\n')
f.write('#include <avr/pgmspace.h>\n\n')

f.write('int16_t const sine_lookup[' + str(len) + '] PROGMEM =')
f.write('\n')
f.write('{' + str.strip(str(sine), '[]') + '};')
f.write('\n')
	
f.write('\n')
f.close()
