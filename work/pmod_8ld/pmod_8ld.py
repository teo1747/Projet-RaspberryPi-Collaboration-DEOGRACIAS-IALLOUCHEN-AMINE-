import time
import sys

from gpio import JA, JB, JC, gpio_set_direction, gpio_set_value

if len(sys.argv) != 4:
    print("Utilisation: {} <port> <combinaison> <duration>".format(sys.argv[0]))
    sys.exit()

port = sys.argv[1]
pattern = int(sys.argv[2], 16)
duration = int(sys.argv[3])
J = None

if port == 'a':
    J = JA
elif port == 'b':
    J = JB
elif port == 'c':
    J = JC
else:
    print("Port inconnu : {}".format(port))
    sys.exit()

for i in range(8):
    gpio_set_direction(J[i], 1)
    if pattern & (1 << i):
        gpio_set_value(J[i], 1)

time.sleep(duration)

for i in range(8):
    gpio_set_value(J[i], 0)
 
