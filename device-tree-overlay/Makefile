
SAMPLE-DTO-00A0.dtbo: build

build: SAMPLE-DTO.dts
	dtc -O dtb -o SAMPLE-DTO-00A0.dtbo -b 0 -@ SAMPLE-DTO.dts 

.PHONY: clean
clean:
	rm SAMPLE-DTO-00A0.dtbo

.PHONY: install
install: SAMPLE-DTO-00A0.dtbo
	cp SAMPLE-DTO-00A0.dtbo /lib/firmware

.PHONY: uninstall
uninstall: 
	rm /lib/firmware/SAMPLE-DTO-00A0.dtbo

.PHONY: load
load:
	echo SAMPLE-DTO > /sys/devices/bone_capemgr.9/slots

.PHONY: unload
unload:
	echo -`cat /sys/devices/bone_capemgr.9/slots | grep SAMPLE-DTO | sed 's/:.*//' | sed 's/ //'` > /sys/devices/bone_capemgr.9/slots
