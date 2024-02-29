class DivisionMethod:

    def __init__(self, size: int):
        self.MAX = size
        self.arr = [None for i in range(self.MAX)]
    
    def getHash(self, key: int):
        h = key%self.MAX
        return h
    
    def __setitem__(self, key, data):
        h = self.getHash(key)
        self.arr[h] = data
    
    def __getitem__(self, key):
        h = self.getHash(key)
        return self.arr[h]
    
d = DivisionMethod(10)
d[1] = 100
d[2] = 190
d[3] = 900
print(f"{d.arr}")
