def main():
	file=input('Enter a file name: ')
	infile=open(file,'read')
	key=infile.readline()
	name_list=[]
	grade_list=[]
	for line in infile:
		name=line[0:7]
		name_list.append(name)
		grade=line[8:]
		grade_list.append(grade)
	record= 'name_list + grade_list'
	grade(record)
def record(grade):
	 
		
	
	
