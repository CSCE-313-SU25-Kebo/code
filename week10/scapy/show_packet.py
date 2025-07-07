# view mycode.py
#!/usr/bin/env python3
from scapy.all import *

pkt = IP()
pkt.dst = "192.0.2.1"
pkt.src = "192.168.8.14"
pkt.ttl = 16
pkt.len = 61
pkt.version = 6

pkt.show()

send(pkt)
