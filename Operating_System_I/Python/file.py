from os.path import exists
from sys import argv
from os import walk

script, fileName, outFile = argv

if exists(fileName):
   print "Reading file %s" %fileName
   with open(fileName) as fin:
       lines = sum(1 for line in fin)
else:
   print "The file name you entered doesn't exist."

if exists(outFile) == False:
   print "Output file DNE, so creating file"

outF = open(outFile, 'a+')
outData = "The input fle contains %d lines\n" %lines
print "Writing to %s\n" %outFile
outF.write(outData)
outF.close()
