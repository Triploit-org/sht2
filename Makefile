OBJ = sht2.o
CC = g++

compile: $(OBJ)
	@echo [CPP] Link SHT2...
	@$(CC) -fpermissive  -lreadline -lcurl -W -o sht2 sht2.o
	@echo [CPP] Finished!
	@echo "–––––––––––––––––––––––––––"
	@rm sht2.o

sht2.o:
	@echo [CPP] Compile SHT2...
	@$(CC) -fpermissive -lreadline -lcurl -W -c sht2.cpp
	@echo [CPP] Finished!
	@echo "–––––––––––––––––––––––––––"

install: compile
	@echo "[CP] sht2 /bin/"
	@sudo cp sht2 /bin/
	@echo [CP] Finished!
	@echo "–––––––––––––––––––––––––––"
