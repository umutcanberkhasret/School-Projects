#Program converts the given DNA strand to its complementary DNA or RNA strand depending on the choice.

fileContent = open("C:\Python27\ATgene.fa", "r")

def RNAcomplementaryconverter(DNA):
	
	rna_comp= ''
	#we are creating a list since we can't operate on string indice by indice.
	templist= list(DNA)
	j=0
	for i in templist:
		
		if templist[j] == 'A':
			templist[j]= 'U'
		
		elif templist[j] == 'G':
			templist[j]= 'C'
		
		elif templist[j] == 'T':
			templist[j]= 'A'
		
		elif templist[j] == 'C':
			templist[j]= 'G'
		j=j+1
	
	
	#at the beginning we have changed the type from string to list.
	#by doing this procedure we have string again.
	
	rna_comp= ''.join(c for c in templist)
	
	#obtained strand must be reversed in order to have 3' to 5' relationship
	#since we are creating its complementary.
	rna_comp= ''.join(reversed(rna_comp))
	
	return rna_comp

	
	
def DNAcomplementaryconverter(DNA):
	
	dna_comp= ''
	#we are creating a list since we can't operate on string indice by indice.
	templist= list(DNA)
	j=0
	for i in templist:
		
		if templist[j] == 'A':
			templist[j]= 'T'
		
		elif templist[j] == 'G':
			templist[j]= 'C'
		
		elif templist[j] == 'T':
			templist[j]= 'A'
		
		elif templist[j] == 'C':
			templist[j]= 'G'
		j=j+1
	
	
	#we changed the strand from string to list before
	#by doing this procedure we have string again.
	
	dna_comp= ''.join(c for c in templist)
	
	#obtained strand must be reversed in order to have 3' to 5' relationship
	#since we are creating its complementary.
	dna_comp= ''.join(reversed(dna_comp))
	
	return dna_comp


#MAIN PART...
print " *****All strand that we will deal here, will be assumed as they start from 5' to 3' *******\n"
DNA_seq= ""

for line in fileContent:
	#To avoid description line, use smth.starstwith(">")
	
	if line.startswith(">"):
		continue
		
	DNA_seq= DNA_seq+line[:-1]
		
while 1:

	print 'Specify the complementary strand type: (1 for DNA, 2 for RNA, 3 for exit...) ' 
	strandtype= input()
	print "\n\n\n"
	
	if strandtype==1:

		DNA_comp= DNAcomplementaryconverter(DNA_seq)
		print "Given DNA Strand: ", DNA_seq ,"\n"
		print "It's complementary DNA strand: ", DNA_comp , "\n"
		print "\n\n\n"

	elif strandtype==2:

		RNA_comp= RNAcomplementaryconverter(DNA_seq)
		print "Given DNA Strand: ", DNA_seq , "\n"
		print "It's complementary RNA strand: ", RNA_comp , "\n"
		print "\n\n\n"
	
	elif input("Press 5 if you wish to continue or press 3 to exit...")==5 :
		continue
	else:
		break 
		
		
		
		
		