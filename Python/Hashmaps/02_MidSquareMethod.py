class MidSquareMethod:

    def __init__(self, size):
        self.size = size
        self.arr = [None for i in range(self.size)]
    
    def getHash(self, key: int):
        h = key*key
        for i in h:
            print(i)

m = MidSquareMethod(100)
m.getHash(10)