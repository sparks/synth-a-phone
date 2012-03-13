# Makin' waves, yo.

import math
import argparse
import matplotlib.pyplot as plot

# Parse dem args.
parser = argparse.ArgumentParser(description='Generate wave tables for sine, triangle, sawtooth, and square waves, given the inputs specified.')
parser.add_argument('-l', '--length', action='store', dest='len', type=int, help='length of the wave table.')
parser.add_argument('-a', '--amplitude', action='store', dest='amp', type=int, help='amplitude of the output waves.')
parser.add_argument('-o', '--octaves', action='store', dest='oct', type=int, help='number of octaves to generate tables for.')
parser.add_argument('-s', '--samplerate', action='store', dest='samp', type=int, help='sampling rate of the device.')

args = parser.parse_args()

len = args.len
amp = args.amp
oct = args.oct
samp = args.samp

# Setup dat sampling.
freq = samp / len

wave_period = 1 / freq
samp_period = 1 / samp

octaves = []

for i in range(oct):
	octaves.append(math.pow(2, i))

# Generate dem wavetables.
sine = []
triangle = []
sawtooth = []
square = []

for j in range(oct):
	sine.append([])
	triangle.append([])
	sawtooth.append([])
	square.append([])
	for i in range(len):
		sine[j].append(amp * math.sin(octaves[j] * i * (samp_period / wave_period) * 2 * math.pi))
		triangle[j].append(4 * amp * (samp_period / wave_period) * -math.fabs(((octaves[j] * i) % (wave_period / samp_period)) - (wave_period / (2 * samp_period))) + amp)
		sawtooth[j].append((2 * amp * octaves[j] * i * (samp_period / wave_period) % (2 * amp)) - amp)
		square[j].append(amp if (((octaves[j] * i) % (wave_period / samp_period)) < (wave_period / (2 * samp_period))) else -amp)
		
# Write dat file.
f = open('wavetable.txt', 'w')

f.write('\n// Sine waves:\n')
for i in range(oct):
	f.write(str(sine[i]))
	f.write('\n')
	
f.write('\n// Triangle waves:\n')
for i in range(oct):
	f.write(str(triangle[i]))
	f.write('\n')

f.write('\n// Sawtooth waves:\n')
for i in range(oct):
	f.write(str(sawtooth[i]))
	f.write('\n')

f.write('\n// Square waves:\n')
for i in range(oct):
	f.write(str(square[i]))
	f.write('\n')

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
