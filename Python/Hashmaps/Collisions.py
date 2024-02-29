class Collision:

    def __init__(self):
        self.MAX = 100
        self.arr = [[] for i in range(self.MAX)]
    
    def getHash(self, key):
        h = 0
        for char in key:
            h+=ord(char)
        return h%self.MAX
    
    # def __setitem__(self, key, val):
    #     h = self.getHash(key)
    #     for index, 66yelement in enumerate(self.arr[h]):
    #         if len(element)==2 and element[0]==key:
    #             element[1] = 
    #     self.arr[h].append((key, val))
    
    def __getitem__(self, key):
        h = self.getHash(key)
        return self.arr[h]

