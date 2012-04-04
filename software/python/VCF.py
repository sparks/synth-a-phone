from pylab import *
from scipy.signal import *
from numpy.polynomial import *

print butter(4, 1)

C1, C2, C3, C4 = 100.0e-12, 200.0e-12, 400.0e-12, 800.0e-12 #Order 2 complex conjugate poles
Iabc = 1e-3 #Range 500uA to 2mA
gm = 19.2*Iabc
alpha = 200.0/(100.0e3+200.0)
beta = gm*alpha

B, A = [1], [C1*C2*C3*C4/beta**4, C2*C3*C4/beta**3, C3*C4/beta**2, C4/beta, 1]

poles = roots(A)
plot(real(poles), imag(poles), 'x')
show()

resp = freqs(B, A)
plot(resp[0], abs(resp[1]))

xscale('log')
yscale('log')
show()