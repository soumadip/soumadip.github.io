# import the PyPDF2 module
import os
import PyPDF2
import re
import glob

mypath=""
files = glob.glob(mypath+"*.pdf")

for file in files:
    # open the pdf file in binary mode
    pdfFileObj = open(file, 'rb')

    # create a pdf reader object
    pdfReader = PyPDF2.PdfReader(pdfFileObj)


    # get the page object
    pageObj = pdfReader.pages[0]
    # extract text from the page
    text = pageObj.extract_text()
    # print the text
    print(text)
    text = re.sub(' +', ' ', text)
    words = text.split()
    print(words)
    for i, word in words:
        print (word)
        if "nrol" in word:
            print (words[i-1, word, word[i+1])

    # close the pdf file object
    pdfFileObj.close()
