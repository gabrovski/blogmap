SOURCE=src/scraper/page.cpp src/scraper/scraper.cpp src/main.cpp src/util/util.cpp
TARGET=blogmap
CC=c++


all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(SOURCE) -g -lcurl -o $(TARGET)

clean:
	rm -f $(TARGET)
