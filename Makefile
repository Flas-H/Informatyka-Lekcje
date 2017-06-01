.PHONY: clean All

All:
	@echo "----------Building project:[ Szyfr_Cezara - Debug ]----------"
	@cd "Szyfr_Cezara" && "$(MAKE)" -f  "Szyfr_Cezara.mk"
clean:
	@echo "----------Cleaning project:[ Szyfr_Cezara - Debug ]----------"
	@cd "Szyfr_Cezara" && "$(MAKE)" -f  "Szyfr_Cezara.mk" clean
