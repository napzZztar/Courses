grammer = []
variabs = []
termins = []
firstof = []
folloof = []

f = open("grammer.txt", "r")

for item in f:
    grammer.append(item.split('\n')[0])

for item in grammer:
    left, right = item.split("->")
    variabs.append(left.strip())

var_set = set(variabs)
variabs = list(var_set)

def findfirst(var):
    first = []
    flag = True
    for item in grammer:
        left, right = item.split("->")
        left = left.strip();
        right = right.split(" ")[1].strip()

        if(left==var):
            if((right not in var_set)):
                first.append(right)
            else:
                flag = False
                first = findfirst(right)
    return first

def findFollow(var):

for item in variabs:
    firstof.append([item, findfirst(item)]);

print firstof

