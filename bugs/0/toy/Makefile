all: toy

toy: toy.o
	$(CC) $(CFLAGS) -DHAVE_CONFIG_H -g -fPIC -DPIC -O0 -o $@ $<

install:
	mkdir -p $(shell pwd)/lava-install/bin
	cp toy $(shell pwd)/lava-install/bin

clean:
	rm -f toy.o toy
