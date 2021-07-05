format: .clang-format
	find . -name "*.[ch]pp" | xargs clang-format -i

.clang-format:
	wget https://gist.githubusercontent.com/remortalite/5a19717025837ea5a1ddcaaa228ee1a9/raw/46493bcd31aaad11626986ccca2fea5b9e782bb6/.clang-format -O $@

.PHONY: format
