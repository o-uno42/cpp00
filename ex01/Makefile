CPP = g++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

TARGET = phoneBook

SRCS = main.cpp PhoneBook.cpp Contact.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

re: clean all
