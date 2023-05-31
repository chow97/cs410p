#!/bin/bash

cc $1 -I/usr/X11R6/include -L/usr/X11R6/lib -lm -lX11 -o output

./output