def main():
    import pickle
    phoneBook={'chris':'555-1234','john':'555-5678','tom':'555-1357','mike':'555-2468',
               'cindy':'555-1256','kristen':'555-6474','will':'555-8474','travis':'555-7464'}
    choice=input('Would you like to look up a phone number? Enter Y/y for yes or N/n for no: ')
    print()
    while choice.lower()=='y':
        print('Here is a list of names in the directory')
        print()
        for x in phoneBook:
            print(x.capitalize())
        print()
        search=input('Enter a name to find a phone number: ')
        print()
        sval=0
        try:
            if search.lower() in phoneBook:
                print(phoneBook[search.lower()],'\n')
                sval+=1
                
                print('Would you like to delete',search.capitalize(),'from the directory?')
                print()
                delete=input('Enter Y/y to delete or N/n if you do NOT want to delete')
                print()
                if delete.lower()=='y':
                    del phoneBook[search.lower()]
                    print()
        except KeyError:
            print(search,'not found.')
        if sval==0:
            print(search,'was not found in the directory.','\n')
            add=input('Enter Y/y to add the name to the directory or N/n if you do NOT want to add.')
            print()
            if add.lower()=='y':
                addphone=input('Please enter the phone number in the format: XXX-XXXX ')
                print()
                phoneBook[search.lower()]=addphone
        choice=input('Would you like to look up a phone number? Enter Y/y for yes or N/n for no: ')
        print()
    file=open('directorydb.txt','wb')
    pickle.dump(phoneBook,file)
    file.close()
main()
