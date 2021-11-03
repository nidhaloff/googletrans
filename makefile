
clean:
	rm -rf build && mkdir -p build && cd build && conan install .. --build=missing

start:
	cd build && cmake .. && make --no-print-directory && ./googletrans

commit:
	git add . && git commit -m "$m"