ifeq ($(strip $(DevKitGBA)),)
$(error "Please set DEVKITARM in your environment. export DevKitGBA=<path to>devkitARM")
endif

DEVKITPRO=$(DevKitGBA)
GBATOOLS=$(GbaTools)

CC=$(DEVKITPRO)arm-none-eabi-g++
CFLAG= -mthumb -mthumb-interwork
INCL = -Isource/

TARGET=TestGBA

SRCDIR=source/
BINDIR=bin/
OUTDIR=build/

SRC=$(subst $(SRCDIR), ,$(wildcard $(SRCDIR)*.cpp))

OBJ=$(SRC:.cpp=.o)

all : $(TARGET)

start : all
	./VisualBoyAdvance.exe $(OUTDIR)$(TARGET).gba

$(TARGET) : $(TARGET).elf
	$(DEVKITPRO)arm-none-eabi-objcopy -O binary $(BINDIR)$< $(OUTDIR)$@.gba
	#$(GBATOOLS)gbafix $(OUTDIR)$@.gba
	./VisualBoyAdvance.exe $(OUTDIR)$(TARGET).gba

$(TARGET).elf : $(OBJ)
	$(CC) -specs=gba.specs $(CFLAG) $(foreach o,$^,$(BINDIR)$(o)) -o $(BINDIR)$@

%.o : $(SRCDIR)%.cpp
	$(CC) $(CFLAG) $(INCL) -o $(BINDIR)$@ -c $<

.PHONY : clean wipe directories

clean :
	rm -f $(BINDIR)*.o
	rm -f $(BINDIR)*.elf
	rm -f $(OUTDIR)*.gba
wipe :
	rm -rf $(BINDIR)
	rm -rf $(OUTDIR)
directories :
	mkdir -p $(BINDIR)
	mkdir -p $(OUTDIR)
