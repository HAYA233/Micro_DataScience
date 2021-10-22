def StepJump(num_step):
    if num_step == 1:
        return 1
    if num_step == 2:
        return 2
    else:
        return StepJump(num_step-1) + StepJump(num_step-2)


x = eval(input())
print(StepJump(x))
