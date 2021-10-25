def characterValue(character):
    if (character == "I"): return 1
    if (character == "V"): return 5
    if (character == "X"): return 10
    if (character == "L"): return 50
    if (character == "C"): return 100
    if (character == "D"): return 500
    if (character == "M"): return 1000


def romanToInt(s):
    if (len(s) == 1): return characterValue(s)
    output = 0
    i = 0
    while(i<len(s)):
        if (i != (len(s) - 1) and characterValue(s[i + 1]) > characterValue(s[i])):
            output = output + characterValue(s[i + 1]) - characterValue(s[i])
            i = i + 2
        else:
            output = output + characterValue(s[i])
            i=i+1
    return output


print(romanToInt("IV"))
