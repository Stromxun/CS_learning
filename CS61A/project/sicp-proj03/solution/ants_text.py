
from utils import *
from ants import *
from ants_strategies import start_with_strategy
import ants
@main
def run(*args):
    Insect.reduce_health = class_method_wrapper(Insect.reduce_health,
            pre=print_expired_insects)
    start_with_strategy(args, interactive_strategy, ants)