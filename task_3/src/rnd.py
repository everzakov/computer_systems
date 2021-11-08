import random
import constants

def get_random_name():
    return "".join(chr(97+random.randint(0, 25)) for _ in range(constants.MAX_NAME_LEN))

def get_random_bool():
    return random.randint(0, 1)

def get_random_type():
    return random.randint(0, 2)

def get_random_weight():
    return random.randint(0, 26)