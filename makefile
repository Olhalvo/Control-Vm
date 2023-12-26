CXX := gcc
CFLAGS := -g 
INCLUDES := ./includes/*.h
EXECUTABLE := Control+Vm
OBJDIR := ./obj

OBJ := $(OBJDIR)/*.o

build:
	@make obj
	@make exec
	@make clean_obj
	@mkdir build
	@mv $(EXECUTABLE).exe ./build

run:
	@make obj
	@make exec
	./$(EXECUTABLE)
	@make clean_run

exec:
	@$(CXX) $(OBJ) -o $(EXECUTABLE)

obj:
	@$(CXX) $(INCLUDES) $(CFLAGS) -c ./src/*.c 
	@mkdir $(OBJDIR)	
	@mv *.o $(OBJDIR)

clean_obj:
	@rm ./includes/*.gch
	@rm -rf $(OBJDIR)

clean_run:
	@make clean_obj
	@rm $(EXECUTABLE)

clean_build:
	@rm -rf build
	