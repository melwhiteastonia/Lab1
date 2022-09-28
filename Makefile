# list/Makefile
# 
# Makefile for list implementation and test file.
#
# <Author>
list: main.c list.c 
	gcc -o list main.c list.c