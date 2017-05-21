.PHONY: clean All

All:
	@echo "----------Building project:[ statystyki_tekstu - Debug ]----------"
	@cd "statystyki_tekstu" && "$(MAKE)" -f  "statystyki_tekstu.mk"
clean:
	@echo "----------Cleaning project:[ statystyki_tekstu - Debug ]----------"
	@cd "statystyki_tekstu" && "$(MAKE)" -f  "statystyki_tekstu.mk" clean
