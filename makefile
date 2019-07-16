src = $(wildcard ./src/*.c ./inc/*.h)
obj = $(src:.c=.o)

libma.a: $(obj)
	ar rcs libam.a $(obj)
.PHONY: clean
clean:
	rm -rf ./src/*.o *.a
