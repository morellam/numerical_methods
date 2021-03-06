#simple Makefile to run the .cpp code
CXX = c++
CXXFLAGS = -Wall -std=c++11 -O3 -o
SRC = ./src
OUT = ./output
TEXTFILES = ./pyplot/*.txt 

makedir :
	@if  [ ! -d "$(OUT)" ]; then mkdir $(OUT); fi

simp: $(SRC)/simpson.cpp 
	@$(CXX) $(CXXFLAGS) $(OUT)/$@ $^
	@echo Running executable... 	
	@./$(OUT)/$@	
	@echo Saving plots with results in "output" directory ...
	@python ./pyplot/plot_simpson_errors.py
		
pendulum : $(SRC)/rungekutta.cpp 
	@$(CXX) $(CXXFLAGS) $(OUT)/$@ $^
	@echo Running executable... 
	@./$(OUT)/$@
	@echo Saving plots with results in "output" directory ...
	@python ./pyplot/plot_ode.py
	
pde: $(SRC)/cranknicolson.cpp 
	@$(CXX) $(CXXFLAGS) $(OUT)/$@ $^
	@echo Running executable... 	
	@./$(OUT)/$@	
	@echo Saving plots with results in "output" directory ...

	@python ./pyplot/plot_pde.py
				
simpson : makedir simp

rungekutta : makedir pendulum

cranknicolson : makedir pde

.PHONY = clean

clean : 
	@rm -f $(TEXTFILES) 
	@rm -r $(OUT)

