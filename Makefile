GTEST_LIB = libgtest.a
GTEST_PATH = lib/$(GTEST_LIB)

.PHONY: format test clean

format: .clang-format
	find . -name "*.[ch]pp" | xargs clang-format -i

.clang-format:
	wget https://gist.githubusercontent.com/remortalite/5a19717025837ea5a1ddcaaa228ee1a9/raw/46493bcd31aaad11626986ccca2fea5b9e782bb6/.clang-format -O $@

test: $(GTEST_PATH)

$(GTEST_PATH): googletest/
	cd googletest &&\
		mkdir -p build &&\
		cd build &&\
	   	cmake .. &&\
		make
	cp googletest/build/lib/$(GTEST_LIB) lib/
	rm -Rf googletest

googletest/:
	git clone https://github.com/google/googletest.git -b release-1.11.0 googletest

clean:
	find . -name '*.[od]' -exec $(RM) '{}' \;
	find . -name '*.gch' -exec $(RM) '{}' \;

