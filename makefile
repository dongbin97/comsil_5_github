cc=g++
target=stack
objects=main.o

$(target):$(objects)
	$(cc) -o $(target) $(objects)

.PHONY:
clean:
	rm $(target) $(objects)
