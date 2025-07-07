# view mycode.py
#!/usr/bin/env python3
from scapy.all import *

my_packet = IP(dst="www.slashdot.org") # Creates a packet
my_packet.show() # Create a packet with the Default values
