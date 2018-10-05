CC = clang
CFLAGS = -std=gnu11 -O2
DRIVER_SRC = driver.c
DRIVER = driver
.PHONY: clean

all: $(DRIVER)
	@echo driver successfully constructed

$(DRIVER): $(DRIVER_SRC)
	$(CC) $(CFLAGS) -o $(DRIVER) $(DRIVER_SRC)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ 

clean: 
	$(RM) *.o *.a *~ $(DRIVER)
