.PHONY: hello
hello:
	@echo "*** use one of these:"
	@echo ""
	@echo "  make model100-build"
	@echo "  make model100-flash"
	@echo ""
	@echo "  make model01-build"
	@echo "  make model01-flash"
	@echo ""
	@echo "*** thanks"
	@echo ""

.PHONY: model100-build
model100-build:
	arduino-cli compile -b keyboardio:gd32:keyboardio_model_100

.PHONY: model100-flash
model100-flash:
	arduino-cli upload -b keyboardio:gd32:keyboardio_model_100 --port /dev/cu.usbmodem6564C4AE13391

.PHONY: model01-build
model01-build:
	arduino-cli compile -b keyboardio:avr:model01

.PHONY: model01-flash
model01-flash:
	arduino-cli upload -b keyboardio:avr:model01 --port	/dev/cu.usbmodemCDkbio011
