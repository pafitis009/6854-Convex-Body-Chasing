test: test.o convex_chasing.o steiner_point_calculation.o
	g++ test.o convex_chasing.o steiner_point_calculation.o -o test

convex_chasing.o: ../convex_chasing.cpp ../convexchasing.h 
	g++ -c ../convex_chasing.cpp

steiner_point.o: ../steiner_point_calculation.cpp ../convexchasing.h 
	g++ -c ../steiner_point_calculation.cpp

test.o: test.cpp test.h
	g++ -c test.cpp


clean:
	rm -f test test.o

# CPPFLAGS=-g -pthread -I/sw/include/root
# LDFLAGS=-g
# LDLIBS=-L/sw/lib/root -lCore -lCint -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint \
#        -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lz -L/sw/lib -lfreetype -lz \
#        -Wl,-framework,CoreServices -Wl,-framework,ApplicationServices -pthread -Wl,-rpath,/sw/lib/root \
#        -lm -ldl

# test: tool.o support.o
#     g++ $(LDFLAGS) -o tool tool.o support.o $(LDLIBS)

# tool.o: tool.cc support.hh
#     g++ $(CPPFLAGS) -c tool.cc
