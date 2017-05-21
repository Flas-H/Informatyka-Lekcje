.PHONY: clean All

All:
	@echo "----------Building project:[ SZF_Tajemniczy_szyfr - Debug ]----------"
	@cd "SZF_Tajemniczy_szyfr" && "$(MAKE)" -f  "SZF_Tajemniczy_szyfr.mk"
clean:
	@echo "----------Cleaning project:[ SZF_Tajemniczy_szyfr - Debug ]----------"
	@cd "SZF_Tajemniczy_szyfr" && "$(MAKE)" -f  "SZF_Tajemniczy_szyfr.mk" clean
