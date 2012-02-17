from pylab import *
import scipy.signal as signal

n = 20
#Lowpass filter
a = signal.firwin(n, cutoff = 0.3, window = 'blackman')
#Highpass filter with spectral inversion
b = - signal.firwin(n, cutoff = 0.6, window = 'blackman'); b[n/2] = b[n/2] + 1
#Combine into a bandpass filter
d = - (a+b); d[n/2] = d[n/2] + 1
#Frequency response

print d

resp = array(signal.freqz(d))

# subplot(221)
# plot(abs(resp[0]), abs(resp[1]))
# subplot(222)
# plot(abs(resp[0]), angle(resp[1]))
# subplot(223)
# stem([i for i,n in enumerate(d)],d)

show()
