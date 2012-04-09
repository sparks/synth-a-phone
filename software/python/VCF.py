from pylab import *
from scipy.signal import *
from numpy.polynomial import *

print butter(4, 1)

C2, C3, C4 = 100.0e-12, 200.0e-12, 470.0e-12 #Order 2 complex conjugate poles
Iabc = 2e-3/4 #Range 500uA to 2mA
print Iabc
gm = 19.6*Iabc
alpha = 220.0/(100.0e3+220.0)
beta = gm*alpha

B, A = [1], [C2*C3*C4/beta**3, C3*C4/beta**2, C4/beta, 1]

poles = roots(A)
plot(real(poles), imag(poles), 'x')
show()

resp = freqs(B, A)
plot(resp[0], abs(resp[1]))

xscale('log')
yscale('log')
show()