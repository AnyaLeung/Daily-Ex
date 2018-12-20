mport abc

# Interface class abstract
class Interface(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractclassmethod
    def connect(self):
        return

# USB class implement
class USB(Interface):
    def connect(self, computer):
        print(computer.__name__, "is connected to USB interface now.")

# Type C class implement
class Type_C(Interface):
    def connect(self, computer):
        print(computer.__name__, "is connected to Type_C interface now.")

# Thunderbolt class implement
class Thunderbolt(Interface):
    def connect(self, computer):
        print(computer.__name__, "is connected to Thunderbolt interface now.")

# Computer class abstract
class Computer(object):
    __metaclass__ = abc.ABCMeta

    def __init__(self):
        self.interface = None

    def setInterface(self, interface):
        self.interface = interface

    @abc.abstractclassmethod
    def use(self):
        return

# Lenovo class implement
class Lenovo(Computer):
    def use(self):
        self.interface.connect(Lenovo)

# DELL class implement
class Dell(Computer):
    def use(self):
        self.interface.connect(Dell)

# ASUS class implement
class ASUS(Computer):
    def use(self):
        self.interface.connect(ASUS)

def client():
    usb = USB()
    typec = Type_C()
    lenovo = Lenovo()
    asus = ASUS()

    lenovo.setInterface(usb)
    lenovo.use()

    asus.setInterface(typec)
    asus.use()

client()

