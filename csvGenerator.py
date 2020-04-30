import os
import re
import sys
import nltk
nltk.download('punkt')
keyWords = ['int','float','double','char','string']

#COMMENT REMOVAL
def commentRemover(text):
    def replacer(match):
        s = match.group(0)
        if s.startswith('/'):
            return " " # note: a space and not an empty string
        else:
            return s
    pattern = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
        re.DOTALL | re.MULTILINE
    )
    return re.sub(pattern, replacer, text)


# List all files in a directory using scandir()
fileList  = []
NameList = []
basepath = r'D:\All D\PEC\SECOND YEAR\SEM 4\SEM 4 SET 1 (D)\EAD,DBproj\Codes\Codes For Sample Testing'
with os.scandir(basepath) as entries:
    for entry in entries:
        fileList.append(basepath+'\\'+entry.name)
ILCm = [[]]
LLCm = [[]]
LWCm = [[]]
for q in range(len(fileList)):
    FO = open(fileList[q],"r")
    code_w_comments = FO.read()
    FO.close()
    code_wo_comments = commentRemover(code_w_comments)
    cL = code_wo_comments.split('\n')
    contentList = []
    for i in cL:
        if(i == len(i) * i[0]):
            continue
        else:
            contentList.append(i)


    #Identifier Length Calculator

    IL = []
    for i in contentList:
        a = nltk.word_tokenize(i)
        if(a[0] in keyWords):
            IL.append(a[1])
    dict1 = {}
    for i in IL:
        ctr=0;
        for j in range(len(i)):
            if(i[j]=='='):
                break;
            ctr+=1
        x = str(ctr)
        if ctr in dict1.keys():
            dict1['ILC_'+x]+=1
        else:
            dict1['ILC_'+x]=1
    ILCdict = dict1

    #Line Length Calculator

    LL = []
    for i in contentList:
        a = nltk.word_tokenize(i)
        length=0
        for x in a:
            length += len(x)
            #print(x)
        LL.append(length)
        #print(a)

    dict2 = {}
    for i in LL:
        if 'LLC_'+str(i) in dict2.keys():
            dict2['LLC_'+str(i)]+=1
        else:
            dict2['LLC_'+str(i)]=1
    LLCdict = dict2

    #Line Word Calculator

    LW = [[]]
    for i in contentList:
        llw=[]
        a = nltk.word_tokenize(i)
        #print(a)
        for j in a:
            if('=' in j):
                continue
            elif(len(j)<=2):
                continue
            elif(len(j)>2):
                llw.append(j)
        LW.append(llw)
    LW.remove([])
    dict3={}
    for i in LW:
        if 'LWC_'+str(len(i)) in dict3.keys():
            dict3['LWC_'+str(len(i))]+=1
        else:
            dict3['LWC_'+str(len(i))]=1
    LWCdict = dict3

    ILCmetric = list(ILCdict.items())
    ILCm.append(ILCmetric)
    LLCmetric = list(LLCdict.items())
    LLCm.append(LLCmetric)
    LWCmetric = list(LWCdict.items())
    LWCm.append(LWCmetric)
    filId=fileList[q]
    filId=filId.replace(basepath+'\\','')
    filler=filId.split('_')
    NameList.append(filler[0])
ILCm.remove([])
LLCm.remove([])
LWCm.remove([])

indices=["SID"]
for i in LLCm:
    for j in i:
        if j[0] in indices:
            continue
        else:
            indices.append(j[0])
for i in LWCm:
    for j in i:
        if j[0] in indices:
            continue
        else:
            indices.append(j[0])
for i in ILCm:
    for j in i:
        if j[0] in indices:
            continue
        else:
            indices.append(j[0])

MakerList=[[]]
for i in range(len(NameList)):
    temp = []
    temp.append(NameList[i])
    for j in LLCm[i]:
        temp.append(j[1])
    for j in LWCm[i]:
        temp.append(j[1])
    for j in ILCm[i]:
        temp.append(j[1])
    MakerList.append(temp)
MakerList.remove([])
import csv
row_list = [[]]
row_list.append(indices)
for i in MakerList:
    row_list.append(i)
row_list.remove([])
with open('trial_dataset.csv', 'w', newline='') as file:
    writer = csv.writer(file)
    writer.writerows(row_list)