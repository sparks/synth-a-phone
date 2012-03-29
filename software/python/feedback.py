from pylab import *
from scipy.signal import *
from numpy.polynomial import *

def feedback_amp():
	B, A = array([0, 0, 0, 0, 1]), array(polypow([1, 1], 4))

	for i in range(5):
		k = i
		Ak = polyadd(A, k*B)
		resp = freqs(B, Ak)
		plot(resp[0], abs(resp[1]), label="k="+str(k))

def exact_vs_approx():
	B1, A1 = [0, 1], [-1, 1]
	B2, A2 = [-1.4, 1], [-1, 1]

	resp = freqs(B1, A1)
	plot(resp[0], abs(resp[1]), label="normal")

	resp = freqs(B2, A2)
	plot(resp[0], abs(resp[1]), label="diff")

feedback_amp()

xscale('log')
yscale('log')
legend()

show()