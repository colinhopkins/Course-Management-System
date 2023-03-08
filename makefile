COURSE = cs240
SEMESTER = spring2023
CP_NUMBER = 2
LASTNAME = Hopkins
GITUSERID = colin-hopkins
EXE = scheduler_cp2

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj


all: scheduler_cp2

scheduler_cp2: scheduler.o course.o build.o cancel.o student.o enroll.o add.o drop.o roster.o schedule.o
	g++ scheduler.o course.o build.o cancel.o student.o enroll.o add.o drop.o roster.o schedule.o -o scheduler_cp2 -g

scheduler.o: scheduler.cpp
	g++ -g -c scheduler.cpp

course.o: course.cpp course.h
	g++ -g -c course.cpp

build.o: build.cpp build.h
	g++ -g -c build.cpp

cancel.o: cancel.cpp cancel.h
	g++ -g  -c cancel.cpp

student.o: student.cpp student.h
	g++ -g -c student.cpp

enroll.o: enroll.cpp enroll.h
	g++ -g -c enroll.cpp

add.o: add.cpp add.h
	g++ -g -c add.cpp

drop.o: drop.cpp drop.h
	g++ -g -c drop.cpp

roster.o: roster.cpp roster.h
	g++ -g -c roster.cpp

schedule.o: schedule.cpp schedule.h
	g++ -g -c schedule.cpp

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f scheduler_cp2 *.o
