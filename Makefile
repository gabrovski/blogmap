SOURCE=src/scraper/page.cpp src/scraper/scraper.cpp src/main.cpp src/util/util.cpp src/indexer/word.cpp src/indexer/indexer.cpp
TARGET=blogmap
CC=c++


all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(SOURCE) -g -lcurl -lboost_regex -o $(TARGET)

clean:
	rm -f $(TARGET)
