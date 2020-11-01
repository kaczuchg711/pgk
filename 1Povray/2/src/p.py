#!/usr/bin/env python3
from subprocess import DEVNULL, STDOUT, check_call

withConfig = True

if withConfig:
    configWord = "conf.ini"
else:
    configWord = ""

try:
    check_call(['povray',configWord, 'miasto.pov'], stdout=DEVNULL, stderr=STDOUT)
except:
    import os
    os.system("povray miasto.pov")