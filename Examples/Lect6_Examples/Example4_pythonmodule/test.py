#!/usr/bin/env python

import sys
import os

home = os.environ['HOME']
#mypythonpath = os.path.join(home,"python/lib/python")
mypythonpath = os.path.join(home,".local/lib/python3.12/site-packages")
sys.path.append(mypythonpath)

import MyModule

MyModule.my_test("Hello World!")
