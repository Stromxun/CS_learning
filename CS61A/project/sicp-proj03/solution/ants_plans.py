import ants
from ants import AssaultPlan

def make_test_assault_plan(ants_impl=None):
    ants_impl = ants_impl or ants
    return AssaultPlan().add_wave(ants_impl.Bee, 3, 2, 1).add_wave(ants_impl.Bee, 3, 3, 1)

def make_easy_assault_plan(ants_impl=None):
    ants_impl = ants_impl or ants_impl
    plan = AssaultPlan()
    for time in range(3, 16, 2):
        plan.add_wave(ants_impl.Bee, 3, time, 1)
    plan.add_wave(ants_impl.Wasp, 3, 4, 1)
    plan.add_wave(ants_impl.NinjaBee, 3, 8, 1)
    plan.add_wave(ants_impl.Hornet, 3, 12, 1)
    plan.add_wave(ants_impl.Boss, 15, 16, 1)
    return plan

def make_normal_assault_plan(ants_impl=None):
    ants_impl = ants_impl or ants
    plan = AssaultPlan()
    for time in range(3, 16, 2):
        plan.add_wave(ants_impl.Bee, 3, time, 2)
    plan.add_wave(ants_impl.Wasp, 3, 4, 1)
    plan.add_wave(ants_impl.NinjaBee, 3, 8, 1)
    plan.add_wave(ants_impl.Hornet, 3, 12, 1)
    plan.add_wave(ants_impl.Wasp, 3, 16, 1)

    #Boss Stage
    for time in range(21, 30, 2):
        plan.add_wave(ants_impl.Bee, 3, time, 2)
    plan.add_wave(ants_impl.Wasp, 3, 22, 2)
    plan.add_wave(ants_impl.Hornet, 3, 24, 2)
    plan.add_wave(ants_impl.NinjaBee, 3, 26, 2)
    plan.add_wave(ants_impl.Hornet, 3, 28, 2)
    plan.add_wave(ants_impl.Boss, 20, 30, 1)
    return plan

def make_hard_assault_plan(ants_impl=None):
    ants_impl = ants_impl or ants
    plan = AssaultPlan()
    for time in range(3, 16, 2):
        plan.add_wave(ants_impl.Bee, 4, time, 2)
    plan.add_wave(ants_impl.Hornet, 4, 4, 2)
    plan.add_wave(ants_impl.Wasp, 4, 8, 2)
    plan.add_wave(ants_impl.NinjaBee, 4, 12, 2)
    plan.add_wave(ants_impl.Wasp, 4, 16, 2)

    #Boss Stage
    for time in range(21, 30, 2):
        plan.add_wave(ants_impl.Bee, 4, time, 3)
    plan.add_wave(ants_impl.Wasp, 4, 22, 2)
    plan.add_wave(ants_impl.Hornet, 4, 24, 2)
    plan.add_wave(ants_impl.NinjaBee, 4, 26, 2)
    plan.add_wave(ants_impl.Hornet, 4, 28, 2)
    plan.add_wave(ants_impl.Boss, 30, 30, 1)
    return plan

def make_extra_hard_assault_plan(ants_impl=None):
    ants_impl = ants_impl or ants
    plan = AssaultPlan()
    plan.add_wave(ants_impl.Hornet, 5, 2, 2)
    for time in range(3, 16, 2):
        plan.add_wave(ants_impl.Bee, 5, time, 2)
    plan.add_wave(ants_impl.Hornet, 5, 4, 2)
    plan.add_wave(ants_impl.Wasp, 5, 8, 2)
    plan.add_wave(ants_impl.NinjaBee, 5, 12, 2)
    plan.add_wave(ants_impl.Wasp, 5, 16, 2)

    #Boss Stage
    for time in range(21, 30, 2):
        plan.add_wave(ants_impl.Bee, 5, time, 3)
    plan.add_wave(ants_impl.Wasp, 5, 22, 2)
    plan.add_wave(ants_impl.Hornet, 5, 24, 2)
    plan.add_wave(ants_impl.NinjaBee, 5, 26, 2)
    plan.add_wave(ants_impl.Hornet, 5, 28, 2)
    plan.add_wave(ants_impl.Boss, 30, 30, 2)
    return plan