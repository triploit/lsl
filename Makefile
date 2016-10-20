OBJ = main.o
CC = g++

compile: $(OBJ)
	@cd obj/
	@echo [CPP] Link lsl...
	@$(CC) -fpermissive -W -fstack-check -o obj/lsl main.o
	@echo [CPP] Finished!
	@echo "–––––––––––––––––––––––––––"
	@rm main.o

main.o:
	@clear
	@echo "–––––––––––––––––––––––––––"
	@echo [CPP] Compile lsl...
	@$(CC) -fpermissive -W -fstack-check -c main.cpp
	@echo [CPP] Finished!
	@echo "–––––––––––––––––––––––––––"

windows:
	@cd obj/
	@clear
	@echo "[ MINGW-W64 ] Compile and Link main.CPP to main.EXE..."
	@i686-w64-mingw32-g++ -W -fstack-check -static -static-libstdc++ -static-libgcc -lpthread -fpermissive -c main.cpp
	@i686-w64-mingw32-g++ -W -fstack-check -static -static-libstdc++ -static-libgcc -lpthread -fpermissive -o obj/lsl.exe main.o
	@echo "[ MINGW-W64 ] Finished!"
	@rm main.o

test: install
	@cd obj/
	@clear
	@lsl obj/test1.lsl

install: compile
	@cd obj/
	@echo "[CP] lsl /bin/"
	@sudo cp obj/lsl /bin/
	@echo [CP] Finished!
	@echo "–––––––––––––––––––––––––––"
