def getsign(number):
    if (number < 0): return "negative"
    return "positive"


def modulus(number):
    if (number < 0): return number * (-1)
    return number


def powernumber(base,power):
    powerNumber = base
    for x in range (0,power-1):
        powerNumber = powerNumber*base
    return powerNumber


def isOuputOutOfRange(givenOutput):
    if(givenOutput < (-1*powernumber(2,31)) or givenOutput > (powernumber(2,31)-1)):
        return 0
    return givenOutput


def reverse(givenNumber):
    sign = getsign(givenNumber)
    givenNumber = modulus(givenNumber)
    output = 0
    while givenNumber > 0:
        y = 10
        z = givenNumber % 10
        output = z + output * y
        givenNumber = givenNumber / 10
    if sign == "negative": output = output * (-1)
    output = isOuputOutOfRange(output)
    return output


print(reverse(1234567890))
