# view mycode.py
#!/usr/bin/env python3
from scapy.all import *

# Create a basic TCP packet
packet = Ether()/IP()/TCP()

# Create a more specific packet
specific_packet = Ether(src="00:11:22:33:44:55", dst="ff:ff:ff:ff:ff:ff")/\
                 IP(src1", dst="192.168.1.2")/\
                 TCP(sport=1234, dport=80)

# Show packet details
specific_packet.show()

# Send packet
# sendp(packet)
sendp(specific_packet)