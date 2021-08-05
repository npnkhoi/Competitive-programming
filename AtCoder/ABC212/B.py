def weak(s):
    if s[0] == s[1] and s[1] == s[2] and s[2] == s[3]:
        return True

    def follow(a, b):
        if ord(b) - ord(a) == 1:
            return True
        if b == '0' and a == '9':
            return True
        return False


    for i in range(3):
        if not follow(s[i], s[i+1]):
            return False
    
    return True

s = input()
if weak(s):
    print('Weak')
else:
    print('Strong')
 