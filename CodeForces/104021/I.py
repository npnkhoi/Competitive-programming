x, y, z = input().split()
x = int(x)
y = int(y)

# Get the hash of the character
mapping_digit = {}
# For digit
for i in range(10):
    mapping_digit[str(i)] = i

currentCount = 10

# For uppercase charatcer
for i in range(65, 65 + 26):
    mapping_digit[chr(i)] = currentCount
    currentCount += 1

# For lowercase letter
for i in range(97, 97 + 26):
    mapping_digit[chr(i)] = currentCount
    currentCount += 1

# Remap from base to character
digit_to_char = {}
for i in mapping_digit:
    digit_to_char[mapping_digit[i]] = i

#print(digit_to_char)

# Done with the mapping base, now do converting to decimal
decimal = 0
coeff = 0
for i in range(len(z) - 1, -1, -1):
    currentDigit = z[i]
    decimal += (int(x) ** coeff) * mapping_digit[currentDigit]
    coeff += 1 
#print(decimal)

# Convert the decimal to base y
baseYConverter = ""
while(decimal > 0):
    current = decimal % y 
    # print(current)
    baseYConverter += (digit_to_char[current])
    decimal //= y

if len(baseYConverter) == 0:
    baseYConverter += '0'

baseYConverter = baseYConverter[::-1]
print(baseYConverter)