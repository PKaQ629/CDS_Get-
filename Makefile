object = main.o CdntGet.o GenenameGet.o CdsGet_cplmt.o cds2str.o join.o
cc = gcc
CDS: $(object)
	cc -o CDS $(object) -L. -lgenbank -I.
clean: 
	rm -rf $(object)
