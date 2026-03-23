#!/usr/bin/env python

import ROOT
from array import array

ROOT.gROOT.SetBatch(True)

def main():
    x = [1,3]
    y = [1,2]

    n = len(x)

    canvas = ROOT.TCanvas("someName","",500,500)
    canvas.SetFillColor(0)
    canvas.cd()

    frame = ROOT.TH2F("frame","",2,0,4,2,0,3)
    frame.SetStats(0)
    frame.GetXaxis().SetTitle("x")
    frame.GetYaxis().SetTitle("y")
    frame.Draw()

    xarr = array("d",x)
    yarr = array("d",y)
    graph = ROOT.TGraph(n,xarr,yarr)
    graph.SetMarkerStyle(2)
    graph.SetMarkerColor(2)
    graph.Draw("PL")

    canvas.Print("graph.eps")
    canvas.Print("graph.png")
    canvas.Print("graph.C")

if __name__ == "__main__":
    main()
