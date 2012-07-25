SOURCE=src/scraper/page.cpp src/scraper/scraper.cpp src/main.cpp
TARGET=blogmap
CC=c++


all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(SOURCE) -lcurl -o $(TARGET)

clean:
	rm -f $(TARGET)
