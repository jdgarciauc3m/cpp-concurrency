FINAL_DIR= final

LATEXMK=latexmk -pdf -file-line-error -halt-on-error -outdir=$(FINAL_DIR) 

CONFIG_SLIDES= \
	common/*.tex \
	config/*.tex \

LOGOS=logos/*

include m1/Makefile.def
include m2/Makefile.def
include guide/Makefile.def

.PHONY: all clean slides guide

all:	slides guide

clean:
	rm -Rf $(FINAL_DIR)

$(FINAL_DIR):
	mkdir -p $(FINAL_DIR)

slides: $(ALL_SLIDES_FINAL_PDF)

guide:	$(GUIDE_FINAL_PDF)

printall:
	echo $(ALL_SLIDES_FINAL_PDF)

include $(M1_DIR)/Makefile.mk
include $(M2_DIR)/Makefile.mk
include $(GUIDE_DIR)/Makefile.mk
