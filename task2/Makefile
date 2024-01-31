# Change this variable to run the analysis on other .c files
program := program
WFLAGS := -Wno-c++17-extensions
# The filename which the shared library writes to and gnuplot reads from
export DATA := histogram.dat

info_llvm_pass.so: info_llvm_pass.cpp
	clang++ $(WFLAGS) $(llvm-config --cxxflags --ldflags --libs core irreader) -fPIC -shared -o info_llvm_pass.so info_llvm_pass.cpp

$(program).bc: $(program).c
	clang -c -emit-llvm $(program).c

llvm_pass: info_llvm_pass.so $(program).bc
	opt -analyze -load ./info_llvm_pass.so -info < $(program).bc > /dev/null

# $(DATA) depends on llvm_pass implicitly
plot_histogram: $(DATA)
	gnuplot histogram.gp

clean:
	$(RM) *.so
	$(RM) *.bc
	$(RM) *.pdf
	$(RM) *.dat

all: plot_histogram
