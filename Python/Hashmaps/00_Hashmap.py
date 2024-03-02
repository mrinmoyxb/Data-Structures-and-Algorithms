class Hashmap:

    def __init__(self):
        self.MAX = 10
        self.arr = [[] for i in range(self.MAX)]
    
    #? hash function:
    #? find the ASCII value of each character of key, and calculate the total sum
    #? mod of total sum by size = [total % size] 
    def getHash(self, key):
        h = 0
        for char in key:
            #* ord returns the ASCII value of characters
            h+=ord(char) 
        return h%self.MAX
    
    def __setitem__(self, key, val):
        h = self.getHash(key)
        self.arr[h] = val
    
    def __getitem__(self, key):
        h = self.getHash(key)
        return self.arr[h]
    
    def __delitem__(self, key):
        h = self.getHash(key)
        self.arr[h] = None

h = Hashmap()
h['jan1'] = 100
h['jan2'] = 120
h['jan3'] = 190
print(f"{h.arr}")
print()

del h['jan2']
print(f"{h.arr}")
    
