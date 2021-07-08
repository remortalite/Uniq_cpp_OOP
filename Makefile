GTEST_LIB = libgtest.a
GTEST_PATH = lib/$(GTEST_LIB)

CLANG_FORMAT = clang-format
CLANG_FORMAT_FLAGS = -i

ifeq (${GITHUB_ACTIONS},true)
	CLANG_FORMAT = clang-format-12
	CLANG_FORMAT_FLAGS := -Wno-error=unknown $(CLANG_FORMAT_FLAGS)
endif

.PHONY: format test clean

format: .clang-format
	find . -name "*.[ch]pp" | xargs $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS)
	@echo Done!

.clang-format:
	wget https://gist.githubusercontent.com/remortalite/5a19717025837ea5a1ddcaaa228ee1a9/raw/0f7661accb30863ca7f620d00a0c07ca66c0ab68/.clang-format -O $@

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

