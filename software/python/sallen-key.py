from pylab import *
from scipy.signal import *

h1_r1 = 4.64e3
h1_r2 = 23.7e3
h1_c1 = 0.001e-6
h1_c2 = 470.0e-12

h1_b = [0, 0, 1/(h1_r1*h1_r2*h1_c1*h1_c2)]
h1_a = [1, (1/(h1_r2*h1_c1)+1/(h1_r1*h1_c1)), 1/(h1_r1*h1_r2*h1_c1*h1_c2)]

h2_r1 = 1e3
h2_r2 = 10.7e3
h2_c1 = 0.01e-6
h2_c2 = 470.0e-12

h2_b = [0, 0, 1/(h2_r1*h2_r2*h2_c1*h2_c2)]
h2_a = [1, (1/(h2_r2*h2_c1)+1/(h2_r1*h2_c1)), 1/(h2_r1*h2_r2*h2_c1*h2_c2)]

h1_b = polymul(h1_b, h2_b)
h1_a = polymul(h1_a, h2_a)

ideal_b = [0, 0, 0, 0, 1]
ideal_a = polymul([1, 0.765, 1], [1, 1.848, 1])

print h1_b
print h1_a

resp = freqs(h1_b, h1_a)
idealresp = freqs(ideal_b, ideal_a)

subplot(221)
xscale('log')
plot(resp[0], abs(array(resp[1])))

subplot(223)
xscale('log')
plot(resp[0], angle(array(resp[1])))

subplot(222)
xscale('log')
plot(idealresp[0], abs(array(idealresp[1])))

subplot(224)
xscale('log')
plot(idealresp[0], angle(array(idealresp[1])))

show()