class WordDictionary:

    def __init__(self):
        self.dico = set()

    def addWord(self, word: str) -> None:
        self.dico.add(word)

    def search(self, word: str) -> bool:
        if word in self.dico:
            return True
        
        
        idx = []
        cnt = 0
        for i in range(len(word)):
            if word[i] == ".":
                idx.append(i)
                cnt += 1

        if cnt == 0:
            return False
        else:
            for element in self.dico:
                
                #print("Searching for word: ", word, "Comparing with: ", element)
                if len(element) != len(word):
                    continue
                element_copy = element
                for i in idx:
                    if i+1 < len(element_copy):
                        
                        element_copy = element_copy[:i] + "." + element_copy[i+1:]
                        #print("Searching for word: ", word, "Comparing with: ", element_copy)
                    else:
                        element_copy = element_copy[:i] + "."
                        #print("Searching for word: ", word, "Comparing with: ", element_copy)
                
                if element_copy == word:
                    return True
            return False
            
                
            
            


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)