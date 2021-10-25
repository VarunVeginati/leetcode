def reverseOfANumber(number):
    output = 0
    while(number>0):
        y = 10
        output = (number % 10) + (output*y)
        number = number/10
    return output


def isPalindrome(x):
    if(x<0): return False
    if(x == reverseOfANumber(x)): return True
    return False

print(isPalindrome(123))