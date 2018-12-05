import abc

# TV product
class TV(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractclassmethod
    def play(self):
        return

# HaierTV product
class HaierTV(TV):
    instance = None
    cloned_instance = None

    def __init__(self):
        raise SyntaxError("Can't generate instance, use get_instance method please")

    @staticmethod
    def get_instance():
        if HaierTV.instance is None:
            print('HaierTV has been produced.')
            HaierTV.instance = object.__new__(HaierTV)
        return HaierTV.instance

    def play(self):
        print('HaierTV is playing...')

    @staticmethod
    def clone(object):
        if HaierTV.cloned_instance is None:
            HaierTV.cloned_instance = object
        return HaierTV.cloned_instance

# HisenseTV product
class HisenseTV(TV):
    instance = None
    cloned_instance = None;

    def __init__(self):
        raise SyntaxError("Can't generate instance, use get_instance method please")

    @staticmethod
    def get_instance():
        if HisenseTV.instance is None:
            print('HisenseTV has been produced.')
            HisenseTV.instance = object.__new__(HisenseTV)
        return HisenseTV.instance

    def play(self):
        print('HisenseTV is playing...')

    @staticmethod
    def clone(object):
        if HisenseTV.cloned_instance is None:
            HisenseTV.cloned_instance = object
        return HisenseTV.cloned_instance

# TV factory
class TVFactory(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractclassmethod
    def produceTV(self):
        return

# HaierTV factory
class HaierTVFactory(TVFactory):
    def produceTV(self):
        return HaierTV.get_instance()

#HisenseTV factory
class HisenseTVFactory(TVFactory):
    def produceTV(self):
        return HisenseTV.get_instance()

# client
def client():
    TV_factory = HaierTVFactory()
    TV = TV_factory.produceTV()
    TV.play()

    print('\n')
    TV_factory = HisenseTVFactory()
    TV = TV_factory.produceTV()
    TV.play()

    print('\nclone HisenseTV')
    TV1 = TV.clone(TV)
    TV1.play()

    print('\nWhether cloned one is equal to the prototype:', TV1==TV)

client()
