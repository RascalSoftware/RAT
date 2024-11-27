import numpy as np

def backgroundFunction(xdata, params):

    # Split up the params array
    Ao = params[0]
    k = params[1]
    back_const = params[2]

    # Make an exponential decay background
    background = np.zeros(len(xdata))
    for i in range(0, len(xdata)):
        background[i] = Ao*np.exp(-k*xdata[i]) + back_const

    return background
