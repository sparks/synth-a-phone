from pylab import *
from scipy.signal import *
from numpy.polynomial import *

def filter(Iabc, label):

	C1, C2, C3, C4 = 100.0e-12, 200.0e-12, 400.0e-12, 800.0e-12  #Order 2 complex conjugate poles
	# Iabc = 2e-5 #Range 500uA to 2mA
	gm = 19.6*Iabc
	alpha = 220.0/(100.0e3+220.0)
	beta = gm*alpha

	B, A = array([0, 0, 0, 0, 1]), array([C1*C2*C3*C4/beta**4, C2*C3*C4/beta**3, C3*C4/beta**2, C4/beta, 1])

	# poles = roots(A)
	# plot(real(poles), imag(poles), 'x')
	# show()

	for i in range(5):
		k = i
		Ak = polyadd(A, k*B)
		resp = freqs(B, Ak)
		if label == 1: plot(resp[0], abs(resp[1]), label="k="+str(k))
		else: plot(resp[0], abs(resp[1]))

	# resp = freqs(B, A)
	# plot(resp[0], abs(resp[1]))

filter(2e-7, 0)
filter(2e-5, 0)
filter(2e-3, 0)

title("4th Order VCF feedback effects")
legend()
xscale('log')
yscale('log')

show()