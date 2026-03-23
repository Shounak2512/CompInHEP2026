#!/usr/bin/env python

# from HiggsAnalysis gitlab repo a script for picking events.
# Config info about pileup and skim counters are also taken into account

import sys
import os
import re
import ROOT
import array

root_re = re.compile(r"(?P<rootfile>([^/]*))\.root")
event_re = re.compile(r"(?P<run>(\d+)):(?P<lumi>(\d+)):(?P<event>(\d+))")

def usage():
    print 
    print("### Usage:   pickEvents.py <root files> -pick <pick events file>")
    print("### Example: pickEvents.py histograms*.root -pick pickEvents.txt")
    print 
    sys.exit()

def main():

    if len(sys.argv) == 1:
        usage()

    rootfiles = []
    pickeventsfile = ""

    iarg = 1
    while iarg < len(sys.argv):
        if sys.argv[iarg] == "-pick" and iarg < len(sys.argv)-1 :
            pickeventsfile = sys.argv[iarg+1]
            iarg += 1
        match = root_re.search(sys.argv[iarg])
        if match:
            rootfiles.append(sys.argv[iarg])
        iarg += 1

    if pickeventsfile == "":
        usage()

    events = getEvents(pickeventsfile)

    for file in rootfiles:
        pick(file,events)


def getEvents(filename):
    events = []
    fIN = open(filename,'r')
    for line in fIN:
        events.append(line.replace("\n", ""))
    return events

def pick(filename,events):

    fIN = ROOT.TFile.Open(filename)

    fName = "picked.root"
    namebody = filename
    match = root_re.search(filename)
    if match:
        namebody = match.group("rootfile")
        fName = filename.replace(namebody,"picked_"+namebody)

    fOUT = ROOT.TFile.Open(fName,'RECREATE')
    intree = fIN.Get("Events")
    if not isinstance(intree, ROOT.TTree):
        print("TTree 'Events' not found. Did you use multicrab file as input (and not pseudomulticrab)?")
        usage()
    
    skimCounter = fIN.Get("configInfo/SkimCounter")
    pileup = fIN.Get("configInfo/pileup")
    fOUT.cd()

    tree = intree.CloneTree(0)

    for event in events:
        match = event_re.search(event)
        if match:
            selection = "run == " + match.group("run") + " && lumi == " + match.group("lumi") + " && event == " + match.group("event")
            picktree = intree.CopyTree(selection)
            treelist = ROOT.TList()
            treelist.Add(picktree)
            tree.Merge(treelist)

    print(namebody," saving",tree.GetEntries(),"events")
    tree.AutoSave()
    cfgInfo = fOUT.mkdir('configInfo')
    cfgInfo.cd()
    pileup.Write()
    skimCounter.Write()
    fIN.Close()
    fOUT.Close()


if __name__ == "__main__":
    main()
