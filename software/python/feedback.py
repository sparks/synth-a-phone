from pylab import *
from scipy.signal import *
from numpy.polynomial import *

B, A = array([0, 0, 0, 0, 1]), array(polypow([1, 1], 4))

print B, A

for i in range(5):
	k = i
	Ak = polyadd(A, k*B)
	resp = freqs(B, Ak)
	plot(resp[0], abs(resp[1]), label="k="+str(k))

xscale('log')
yscale('log')
legend()

show()