import urllib2
import sys
wholeurl = 'http://dict-co.iciba.com/api/dictionary.php?w='+sys.argv[1]+'&key=1F9CA812CB18FFDFC95FC17E9C57A5E1'
content = urllib2.urlopen(wholeurl).read()
def save(filename, contents): 
    fh = open(filename, 'w') 
    fh.write(contents) 
    fh.close() 
save('tmp',content)
#print(content)