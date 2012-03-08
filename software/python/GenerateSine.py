import math
import argparse
import matplotlib.pyplot as plot

parser = argparse.ArgumentParser(description='Generate wave tables for sine, triangle, sawtooth, and square waves, given the inputs specified.')
parser.add_argument('-l', '--length', type=int, help='length of the wave table')

len = 256
amp = 10
samp = 8192
freq = 440

sine = []
triangle = []
sawtooth = []
square = []

for i in range(len):
	sine.append(amp * math.sin(i * 2 * math.pi / len))
	triangle.append(2 * amp * math.fabs(1 - 2 * i / len) - amp)
	sawtooth.append(2 * amp * i/len - amp)
	square.append(2 * amp * (1 if i > 127 else 0) - 10)

plot.subplot(221)
plot.plot(sine, 'b.')

plot.subplot(222)
plot.plot(triangle, 'g.')

plot.subplot(223)
plot.plot(sawtooth, 'r.')

plot.subplot(224)
plot.plot(square, 'k')
plot.show()
