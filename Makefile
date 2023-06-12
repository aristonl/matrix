all:
	$(MAKE) -C src
	$(MAKE) -C wav

clean:
	$(MAKE) -C src clean
	$(MAKE) -C wav clean

matrix:
	$(MAKE) -C src

wav:
	$(MAKE) -C wav

libwav:
	$(MAKE) -C wav/lib
