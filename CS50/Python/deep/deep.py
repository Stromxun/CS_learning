str = input('What is the Answer to the Great Question of Life, the Universe, and Everything?').lower()
if(str.find('42') != -1 or str.find('forty two') != -1 or str.find('forty-two') != -1):
    print('Yes')
else:
    print('No')
