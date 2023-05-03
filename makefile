all: compile
	@./a.out
	
compile:
	@gcc $(V).c -lGL -lGLU -lglut -lm 
clean:
	@echo "Cleaning up..."
	@rm -f *.out

