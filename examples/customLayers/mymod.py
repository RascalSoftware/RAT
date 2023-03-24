# mymod.py
def customfunc():
    """Display message."""
    return 'version 1'

"""Python module demonstrates passing MATLAB types to Python functions"""
def search(words):
    """Return list of words containing 'son'"""
    newlist = [w for w in words if 'son' in w]
    return newlist

def theend(words):
    """Append 'The End' to list of words"""
    words.append('The End is Nigh')
    return words

def test():
    return 'Hello World'

def anotherTest(arr):
    """Return the inputted array"""
    return arr