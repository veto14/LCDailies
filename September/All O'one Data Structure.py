from sortedcontainers import SortedDict

class AllOne:

    def __init__(self):
        self.count = {}
        self.freq = SortedDict()  
        self.max_freq = 0

    def inc(self, key: str) -> None:
        if key not in self.count:
            self.count[key] = 0
        
        old_freq = self.count[key]
        new_freq = old_freq + 1
        self.count[key] = new_freq

        if old_freq > 0:
            self.freq[old_freq].remove(key)
            if not self.freq[old_freq]:
                del self.freq[old_freq]

        if new_freq not in self.freq:
            self.freq[new_freq] = set()
        self.freq[new_freq].add(key)

        self.max_freq = max(self.max_freq, new_freq)

    def dec(self, key: str) -> None:
        old_freq = self.count[key]
        new_freq = old_freq - 1

        self.freq[old_freq].remove(key)
        if not self.freq[old_freq]:
            del self.freq[old_freq]

        if new_freq > 0:
            self.count[key] = new_freq
            if new_freq not in self.freq:
                self.freq[new_freq] = set()
            self.freq[new_freq].add(key)
        else:
            del self.count[key] 

        if old_freq == self.max_freq and old_freq not in self.freq:
            self.max_freq -= 1

    def getMaxKey(self) -> str:
        if self.max_freq == 0:
            return ""
        return next(iter(self.freq[self.max_freq]))

    def getMinKey(self) -> str:
        if not self.freq:
            return ""
        return next(iter(self.freq[self.freq.iloc[0]])) 