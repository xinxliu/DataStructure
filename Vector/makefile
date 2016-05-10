CXX=g++ -std=gnu++14
obj=Vector.o
target=main

$(target):$(obj) 
	$(CXX) -o $(target) $(obj) main.cpp
	
$(obj):Vector.hpp

.PHONY:clean
clean:
	rm -f $(obj) $(target)

