from ctypes import cdll
lib = cdll.LoadLibrary('./timesTwo.so')

class timesTwo(object):
    def __init__(self):
        self.obj = lib.timesTwo_new()

    def timesTwo(self):
        lib.timesTwo_timesTwo(self.obj)
        
        