# Intro to Data Structures & Algorithms Final Project 

## About

The point of this project is to build a user interactive program to create and manage university waitlists. This project is for learning purposes, however, the intended end user would be an employee working for a College or University's admissions department that maintains a waitlist of students. Students on the waitlist are considered qualified, but have not officially been accepted to the school. When enrollment of the already accepted students is below expectations, the school will simply offer admission to students on the waitlist, starting with the student at the front of the list. 

When accepted student enrollment reaches higher than expected levels, the school will want to remove students from the waitlist so that those students know the school is no longer an option for them, and they can get on with making their decision to attend a different school. 

To implement the waitlist, a double-ended queue or 'deque' data structure is used. The deque will be implemented with a doubly-linked list.  A deque is a good DS for a waitlist because the admissions staffer will need quick access to students at the top and bottom of the deque. The student with the highest prority in the deque will be offered admission first. When the school needs to reduce the size of its list, the staffer can easily shrink the list by a certain number, and the students at the back of the list will be removed first. 

The staffer can also search for specific students and remove them if they wish to offer them admission or terminate them from the waitlist.



## Navigation

This directory contains three folders, 'code', 'lists_CSV', and 'testing'.

The code folder is where the code and makefile are located. You should navigate here to use the program.

The lists_CSV folder contains all of the lists the user has created, and is the destination where new lists are saved.

The testing folder contains 'debug.txt' and 'test.txt', which are used for testing and debugging.

## How to use the make file

If your machine can build with g++, simply navigate to the code folder in the console, and type 'make' then press return.

If you receive an error, you may need to compile the .cpp files on your own. Please see the make file for dependencies.

## How to run and use the code

Once the code is compiled, remain in the code folder and type './main' which will run the program. Type 'help' and press return for a listo f commands.

## How to test the code

This data structure is implemented with a UI, and will be tested with the UI. The 'test.txt' file contains a list of commands to type in and outputs to verify to make sure the program if working properly. 

The 'debug.txt' is just a sample debugging, there for the user to debug the program if desired.

