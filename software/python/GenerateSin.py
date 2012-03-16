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

#sine.append([])
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
	
#f.write('\n// Triangle waves:\n')
#for i in range(oct):
#	f.write('{' + str.strip(str(triangle[i]), '[]') + '}')
#	f.write('\n')

#f.write('\n// Sawtooth waves:\n')
#for i in range(oct):
#	f.write('{' + str.strip(str(sawtooth[i]), '[]') + '}')
#	f.write('\n')

#f.write('\n// Square waves:\n')
#for i in range(oct):
#	f.write('{' + str.strip(str(square[i]), '[]') + '}')
#	f.write('\n')

f.write('\n')
f.close()
		
# If generating at least 4 octaves, you can uncomment everything below to visualize the wavetables as a plot

# plot.subplot(4, 4, 1)
# plot.plot(sine[0], 'b.')

# plot.subplot(4, 4, 2)
# plot.plot(sine[1], 'b.')

# plot.subplot(4, 4, 3)
# plot.plot(sine[2], 'b.')

# plot.subplot(4, 4, 4)
# plot.plot(sine[3], 'b.')

# plot.subplot(4, 4, 5)
# plot.plot(triangle[0], 'g')

# plot.subplot(4, 4, 6)
# plot.plot(triangle[1], 'g')

# plot.subplot(4, 4, 7)
# plot.plot(triangle[2], 'g')

# plot.subplot(4, 4, 8)
# plot.plot(triangle[3], 'g')

# plot.subplot(4, 4, 9)
# plot.plot(sawtooth[0], 'r')

# plot.subplot(4, 4, 10)
# plot.plot(sawtooth[1], 'r')

# plot.subplot(4, 4, 11)
# plot.plot(sawtooth[2], 'r')

# plot.subplot(4, 4, 12)
# plot.plot(sawtooth[3], 'r')

# plot.subplot(4, 4, 13)
# plot.plot(square[0], 'k')

# plot.subplot(4, 4, 14)
# plot.plot(square[1], 'k')

# plot.subplot(4, 4, 15)
# plot.plot(square[2], 'k')

# plot.subplot(4, 4, 16)
# plot.plot(square[3], 'k')
# plot.show()
