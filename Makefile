CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = bithbox
SRC = main.c applets/echo.c applets/cat.c applets/ls.c
OBJS = $(SRC:.c=.o)

all: $(TARGET) symlinks

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create symbolic links to trigger the BusyBox illusion
symlinks: $(TARGET)
	ln -sf $(TARGET) echo
	ln -sf $(TARGET) cat
	ln -sf $(TARGET) ls

clean:
	rm -f $(OBJS) $(TARGET) echo cat ls