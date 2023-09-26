pattern=""
char = "A"

for i in range(26):
	b = bytes(char, 'utf-8')
	b = b[0] + i
	letter = chr(b)
	for j in range(10):
		pattern+=letter*3
		pattern+=str(j)

print(pattern)
