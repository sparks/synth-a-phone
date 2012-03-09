import math
import argparse
import matplotlib.pyplot as plot

parser = argparse.ArgumentParser(description='Generate wave tables for sine, triangle, sawtooth, and square waves, given the inputs specified.')
parser.add_argument('-l', '--length', action='store', dest='len', type=int, help='length of the wave table.')
parser.add_argument('-a', '--amplitude', action='store', dest='amp', type=int, help='amplitude of the output waves.')
parser.add_argument('-f', '--frequency', action='store', dest='freq', type=int, help='frequency of the output waves.')
parser.add_argument('-s', '--samplerate', action='store', dest='samp', type=int, help='sampling rate of the device.')

args = parser.parse_args()

len = args.len
amp = args.amp
freq = args.freq
samp = args.samp

wave_period = 1 / freq
samp_period = 1 / samp

sine = []
triangle = []
sawtooth = []
square = []

for i in range(len):
	sine.append(amp * math.sin(i * (samp_period / wave_period) * 2 * math.pi))
	triangle.append(4 * amp * (samp_period / wave_period) * -math.fabs((i % (wave_period / samp_period)) - (wave_period / (2 * samp_period))) + amp)
	sawtooth.append((2 * amp * i * (samp_period / wave_period) % (2 * amp)) - amp)
	square.append(amp if ((i % (wave_period / samp_period)) < (wave_period / (2 * samp_period))) else -amp) 

plot.subplot(221)
plot.plot(sine, 'b')

plot.subplot(222)
plot.plot(triangle, 'g')

plot.subplot(223)
plot.plot(sawtooth, 'r')

plot.subplot(224)
plot.plot(square, 'k')
plot.show()
