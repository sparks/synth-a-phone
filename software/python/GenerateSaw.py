import math
from pylab import * 

base_freq = [25.96, 41.20, 65.41, 103.83, 164.81, 261.62, 415.30, 659.25, 1046.50, 1661.21, 2637.01, 4185.98]
max_limit = [0.87, 0.88, 0.85, 0.92, 1.00, 1.00, 1.00, 0.99, 0.98, 0.97, 0.94, 0.92]
max_amp = 2047
length = 256
sampling_freq = 31250

tables = []

for i in range(len(base_freq)):
	print i
	tables.append([])
	max_k = int(round((sampling_freq/2 -base_freq[i])/base_freq[i]))
	#print(max_k)
	amp = int(round(max_amp*max_limit[i]))
	for j in range(length):
		#print(j)
		term = 0.0
		for k in range(1,max_k):
			#print(k)
				term += (1.0/k)*math.sin(math.pi*2*k*j/length)
		tables[i].append((int(round((amp*(0.5 - 1.0/math.pi*term))))))

#for i, subtab in enumerate(tables):
#	plot(subtab, label=str(i))
#
#legend()
#show()

f = open('wavetable_saw' + str(length) + '.h', 'w')

f.write('#include <avr/pgmspace.h>\n\n')


f.write('int16_t const saw_lookup[' + str(len(base_freq)) + '][' + str(length) + '] PROGMEM =')
f.write('\n')
f.write('{')
for i in range(len(base_freq)):
	f.write('{' + str.strip(str(tables[i]), '[]') + '}')
	if i != len(base_freq) - 1 :
		f.write(',')
	f.write('\n')
f.write('};')
f.write('\n')
	
f.write('\n')
f.close()
				
		
