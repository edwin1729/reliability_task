program := program
WFLAGS := -Wno-c++17-extensions

info_llvm_pass.so: info_llvm_pass.cpp
	clang++ $(WFLAGS) $(llvm-config --cxxflags --ldflags --libs core irreader) -fPIC -shared -o info_llvm_pass.so info_llvm_pass.cpp

$(program).bc: $(program).c
	clang -c -emit-llvm $(program).c

task2: info_llvm_pass.so $(program).bc
	opt -analyze -load ./info_llvm_pass.so -info < $(program).bc > /dev/null

clean:
	$(RM) *.so
	$(RM) *.bc
