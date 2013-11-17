from os.path import exists
from sys import argv
import glob

script, path, outFile = argv
path = "%s*" %path
filePth = glob.glob(path)
print "Entered path : "+path

if exists(outFile):
   print "Accesing output file"
else:
   print "Output file DNE"
   print "Press Enter to create"
   print "Press CTRL+C to cancle"
   raw_input()
   print "File created!"
   
outFile = open(outFile, 'w+')
outFile.write("File Name              -            No of LIne\n")

print "Counting line no...."

for file in filePth:
   if file[-4:] != ".zip":
      with open(file) as fin:
         lines = sum(1 for line in fin)
      str = "%s     -   %d\n" %(file, lines)
      outFile.write(str)
print "\nAll DONE!!"

outFile.close()
