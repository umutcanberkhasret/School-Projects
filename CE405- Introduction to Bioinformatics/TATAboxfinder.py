
'''Simple algorithm to find "TATA" boxes that points where a genetic sequence can be
read and decode. '''

fileContent = open("C:\Python27\ATgene.fa", "r")

# While operating on files; "r" : read only , "w" : write , "a" : append
# In FASTA  format, the line which contains > sign referred for description of the following gene.


seq= ""

for line in fileContent:
	#To avoid description line, use smth.starstwith(">")
	
	if line.startswith(">"):
		continue
		
	seq= seq+line[:-1]

print seq , "\n"

for ind,nuc in enumerate(seq):
	if seq[ind:ind+7]=="TATAAAT":
		print ind+1, "-> ",ind+7
		print seq[ind: ind+7]
		
	if seq[ind:ind+7]== "TATAAAA" : 
		print ind+1 , "->" , ind+7
		print seq[ind: ind+7]
		
	if seq[ind:ind+7]=="TATATAA":
		print ind+1, "-> ",ind+7
		print seq[ind: ind+7]
		
	if seq[ind:ind+7]=="TATATAT":
		print ind+1, "-> ",ind+7
		print seq[ind: ind+7]

		
''' Same result could have been achieved with following simple code as well;

bt1=seq.find("TATAAAT")
bt2=seq.find("TATAAAA")  
bt3=seq.find("TATATAA")
bt4=seq.find("TATATAT")

if bt1 != -1:
 print bt1 
if bt2 != -1:
 print bt2  
if bt3 != -1:
 print bt3
if bt4 != -1:
 print bt4 
 '''
 
