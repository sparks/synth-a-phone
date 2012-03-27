from pylab import *
from scipy.signal import *
from numpy.polynomial import *

B, A = [0, 0, 1, 1], polypow([1, 1], 6)

for k in range(1, 10):
	Ak = polyadd(A, k*B)
	resp = freqs(B, Ak)
	plot(resp[0], abs(resp[1]), label="k="+str(k))

# plot([1, 1], [1e-5, 1])
# plot(resp[0], [1/10**(3.0/20) for i in resp[0]])

xscale('log')
# yscale('log')
legend()

show()
