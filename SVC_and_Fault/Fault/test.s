	AREA XYZ,CODE,READONLY
	EXPORT sqr
sqr
	MOV R1,R2
	MOV R0,#0x40000000; Non-exectable regin
    BX R0;
	END
		
		
		
