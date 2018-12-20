class WordsFactory():
    # construct a dict named words to save all words
    def __init__(self):
        self.words = dict()

    # If words doesn't contain the value, insert.
    # Else return mapping value
    def getWord(self, word):
        if word in self.words.keys():
            return self.words.get(word)
        else:
            self.words[word] = Word(word)
            return self.words.get(word)

    def setColour(self, colour):
        for key, value in self.words.items():
            value.setColour(colour)
    def setSize(self, size):
        for key, value in self.words.items():
            value.setSize(size)

class Word():
    def __init__(self, string):
        self.content = string
    def setSize(self, size):
        self.size = size.getSize()
    def setColour(self, colour):
        self.colour = colour.getColour()


class Size():
    def __init__(self, size):
        self.size = size
    def getSize(self):
        return self.size

class Colour():
    def __init__(self, colour):
        self.colour = colour
    def getColour(self):
        return self.colour

if __name__=='__main__':
    wordsfac = WordsFactory()
    w = wordsfac.getWord("New Word1")
    w1 = wordsfac.getWord("New Word2")

    wordsfac.setColour(Colour("Blue"))
    wordsfac.setSize(Size("16"))

